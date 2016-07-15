#include <stdio.h>
#include <stdlib.h>
#define MAXQSIZE 100

typedef int type;
typedef struct
{
   type *base;
   int front;
   int rear;
}SqQueue;

SqQueue QueueInit()
{
   SqQueue Q;
   Q.base=(type *)malloc(MAXQSIZE*sizeof(type));
   if(!Q.base) exit(0);
   Q.front=Q.rear=0;
   return Q;
}

int QueueLength(SqQueue Q)
{
   return (Q.rear-Q.front+MAXQSIZE)%MAXQSIZE;
}

SqQueue EnQueue(SqQueue Q,type e)
{
   if((Q.rear+1)%MAXQSIZE==Q.front) exit(0);
   Q.base[Q.rear]=e;
   Q.rear=(Q.rear+1)%MAXQSIZE;
   return Q;
}

SqQueue DeQueue(SqQueue Q,type *e)
{
   if(Q.front==Q.rear) exit(0);
   *e=Q.base[Q.front];
   Q.front=(Q.front+1)%MAXQSIZE;
   return Q;
}

type GetTop(SqQueue Q)
{
   type e;
   if(Q.rear==Q.front) exit(0);
   e=Q.base[Q.front];
   return e;
}

void Traverse(SqQueue Q)
{
   while(Q.rear!=Q.front)
   {
      printf("%d ",Q.base[Q.front]);
      Q.front=(Q.front+1)%MAXQSIZE;
   }
   printf("\n");
}

int main()
{
   SqQueue Q;type e;int len;
   Q=QueueInit();
   Q=EnQueue(Q,1);  Q=EnQueue(Q,2);  Q=EnQueue(Q,3);
   Traverse(Q);
   Q=DeQueue(Q,&e);
   Traverse(Q);
   e=GetTop(Q);
   printf("%d\n",e);
   len=QueueLength(Q);
   printf("%d\n",len);

   return 0;
}
