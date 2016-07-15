//迷宫问题、网上例程
#include <stdio.h>
#include <stdlib.h>

#define STACK_INIT_SIZE 100
#define STACKINCREASE 10
#define MAZESIZE 8

typedef struct Postion
{
	int x;
	int y;
}Postion;
typedef struct mazenode
{
	struct Postion pos;//current location
	int curstep;//current step number
	int dir;//current direction
}mazenode;

typedef struct Sqstack
{
	struct mazenode **base;//store point of BiTNode
	struct mazenode **top;
	int stacksize;
}Sqstack;

void initStack(struct Sqstack *s)
{
	s->base=(struct mazenode **)malloc(STACK_INIT_SIZE*sizeof(struct mazenode *));
	if(!s->base)
	{
		printf("allocation fails!");
		exit(-1);
	}
	s->top=s->base;
	s->stacksize=STACK_INIT_SIZE;
}

void Push(struct Sqstack *s,struct mazenode * e)
{
	if((s->top-s->base)>=STACK_INIT_SIZE)
	{
		s->base=(struct mazenode **)realloc(s->base,(STACK_INIT_SIZE+STACKINCREASE)*sizeof(struct mazenode *));
		if(!s->base)
		{
			printf("allocation fails!");
			exit(-1);
		}
		s->top=s->base+STACK_INIT_SIZE;
		s->stacksize=STACK_INIT_SIZE+STACKINCREASE;
	}
	*s->top++=e;
}

void Pop(struct Sqstack *s,struct mazenode **e)
{
	if(s->base==s->top)
	{
		printf("the stack is empty!");
		exit(0);
	}
	*e=*(--s->top);
}

int getTop(struct Sqstack *s,struct mazenode ** e)
{
	if(s->base==s->top)
	{
		printf("the stack is empty!");
		return 0;
	}
	else
	{
		*e=*(s->top-1);
		return 1;
	}
}

int emptyStack(struct Sqstack *s)
{
	if(s->base==s->top)
	{
		return 1;//stack is empty!
	}
	else
	{
		return 0;//stack is not empty!
	}
}

int Pass(struct Postion pos,int array[MAZESIZE][MAZESIZE])
{
	if(array[pos.x][pos.y]!=0&&array[pos.x][pos.y]!=-1)
	{
		return 1;//indicate the way can pass
	}
	else
	{
		return 0;//indicate the way can not pass
	}
}

struct Postion nextPos(struct Postion pos,int dir)
{
	//contrarotate（逆时针旋转）
	switch(dir)
	{
		case 1:pos.y+=1;break;
		case 2:pos.x-=1;break;
		case 3:pos.y-=1;break;
		case 4:pos.x+=1;break;
		default:break;
	}
	return pos;
}


void markFoot(int arr[MAZESIZE][MAZESIZE],struct Postion pos)
{
	arr[pos.x][pos.y]=0;//have pass by the way
}

void markblock(int arr[MAZESIZE][MAZESIZE],struct Postion pos)
{
	arr[pos.x][pos.y]=-1;//do not pass by the postion
}



//function of processing maze
int processMaze(int arr[MAZESIZE][MAZESIZE],struct Postion start,struct Postion end)
{
	struct Sqstack s;
	struct mazenode *p=(struct mazenode*)malloc(sizeof(struct mazenode));
	struct mazenode *nodelist=(struct mazenode *)malloc(100*sizeof(struct mazenode));//put down the way of sucess!
	int curstep=1,flag=0;
	struct Postion curpos=start,temp;
	initStack(&s);
	do
	{
		if(Pass(curpos,arr))
		{
			markFoot(arr,curpos);
			//struct mazenode node;
			nodelist[flag].pos=curpos;
			nodelist[flag].curstep=curstep;
			nodelist[flag].dir=1;//towards east
			Push(&s,nodelist+flag);
			flag++;
			if(curpos.x==end.x&&curpos.y==end.y)
			{
				while(!emptyStack(&s))
				{
					Pop(&s,&p);
					arr[p->pos.x][p->pos.y]=p->curstep;
				}
				return 1;
			}
			curstep++;
			curpos=nextPos(curpos,1);//towards east
		}
		else
		{
			if(!emptyStack(&s))
			{
				Pop(&s,&p);
				while(p->dir==4&&!emptyStack(&s))
				{
					markblock(arr,p->pos);//mark that the way is not passed
					Pop(&s,&p);
					curstep--;
				}
				if(p->dir<4)
				{
					p->dir++;
					Push(&s,p);
					temp=p->pos;
					curpos=nextPos(temp,p->dir);
				}
			}
		}
	}
	while(!emptyStack(&s));
	return 0;//failure
}

int main()
{
	int maze[8][8]={{0,0,0,0,0,0,0,0},{0,0,1,0,0,1,0,0},{0,1,1,0,0,0,1,0},
	{0,1,0,0,0,0,0,0},{0,1,1,1,0,0,1,0},{0,0,0,1,0,0,1,0},
	{0,0,0,1,1,1,1,0},{0,0,0,0,0,0,0,0}},i,j,flag;
	struct Postion start,end;
	start.x=1;start.y=2;
	end.x=4;end.y=6;
	printf("primative maze:\n");
	for(i=0;i<MAZESIZE;i++)
	{
		for(j=0;j<MAZESIZE;j++)
		{
			printf("%2d",maze[i][j]);
		}
		printf("\n");
	}
	flag=processMaze(maze,start,end);
	if(flag==1)
	{
	    printf("maze processing success!\n");
	    printf("processed maze:\n");
		for(i=0;i<MAZESIZE;i++)
		{
			for(j=0;j<MAZESIZE;j++)
			{
				printf("%2d",maze[i][j]);
			}
			printf("\n");
		}
	}
	else
	{
		printf("maze processing fail!\n");
	}
	return 0;
}

