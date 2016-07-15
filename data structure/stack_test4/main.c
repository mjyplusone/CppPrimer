//表达式求值
#include <stdio.h>
#include <stdlib.h>
#define STACK_INIT 100
#define STACK_ADD 10

char priority[7][7]={{'>','>','<','<','<','>','>'},
                     {'>','>','<','<','<','>','>'},
                     {'>','>','>','>','<','>','>'},
                     {'>','>','>','>','<','>','>'},
                     {'<','<','<','<','<','=',' '},
                     {'>','>','>','>',' ','>','>'},
                     {'<','<','<','<','<',' ','='}};

typedef char type;
typedef struct
{
   type *base,*top;
   int stacksize;
}SqStack;

void StackInit(SqStack *s)
{
   s->base=(type*)malloc(STACK_INIT*sizeof(type));
   if(!s->base) exit(0);
   s->top=s->base;
   s->stacksize=STACK_INIT;
}

void Push(SqStack *s,type e)
{
   if(s->top-s->base>=s->stacksize)
   {
      s->base=(type*)realloc(s->base,(s->stacksize+STACK_ADD)*sizeof(type));
      if(!s->base) exit(0);
      s->top=s->base+s->stacksize;
      s->stacksize+=STACK_ADD;
   }
   *s->top++=e;
}

void Pop(SqStack *s,type *e)
{
   if(s->top==s->base) exit(0);
   *e=*--s->top;
}

type GetTop(SqStack *s)
{
   type e;
   if(s->top==s->base) exit(0);
   e=*(s->top-1);
   return e;
}

void Traverse(SqStack *s)
{
   while(s->top!=s->base)
      printf("%c ",*--s->top);
   printf("\n");
}

char Operate(char a,char theta,char b)
{
   int result,aa,bb;
   char res;
   aa=a-'0'; bb=b-'0';
   switch(theta)
   {
      case '+':result=aa+bb; break;
      case '-':result=aa-bb; break;
      case '*':result=aa*(bb); break;
      case '/':result=aa/(bb); break;
   }
   res=result+'0';
   return res;
}

int Match(char a)
{
   int num;
   switch(a)
   {
      case '+':num=0;break;
      case '-':num=1;break;
      case '*':num=2;break;
      case '/':num=3;break;
      case '(':num=4;break;
      case ')':num=5;break;
      case '#':num=6;break;
   }
   return num;
}

char Precede(char a,char b)
{
   int num1,num2;
   num1=Match(a); num2=Match(b);
   return priority[num1][num2];
}

int In(char c)//是否为运算符
{
   if(c>='0' && c<='9') return 0;
   else return 1;
}

int EvaluateExpression()
{
   char ch; type e,theta,a,b;
   SqStack OPTR,OPND;    //OPTR为运算符栈，OPND为运算数栈
   StackInit(&OPTR); StackInit(&OPND);
   Push(&OPTR,'#');
   ch=getchar();
   while(ch!='#' || GetTop(&OPTR)!='#')
   {
      if(!In(ch))
      {
         Push(&OPND,ch);
         ch=getchar();
      }
      else
      {
         switch(Precede(GetTop(&OPTR),ch))
         {
            case '<':Push(&OPTR,ch); ch=getchar(); break;
            case '=':Pop(&OPTR,&e); ch=getchar(); break;
            case '>':Pop(&OPTR,&theta);Pop(&OPND,&b);Pop(&OPND,&a);
                     Push(&OPND,Operate(a,theta,b)); break;
         }
      }
   }
   return GetTop(&OPND);
}

int main()
{
    type ch; int result;
    ch=EvaluateExpression();
    result=ch-'0';
    printf("%d\n",result);

    return 0;
}
