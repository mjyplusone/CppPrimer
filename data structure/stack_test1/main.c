//数制转换
#include <stdio.h>
#include <stdlib.h>
#define STACK_INIT_SIZE 100
#define STACK_ADD 10

typedef int type;
typedef struct
{
   type *base,*top;
   int stacksize;
}SqStack;

SqStack StackInit()
{
   SqStack s;
   s.base=(type *)malloc(STACK_INIT_SIZE*sizeof(type));
   if(!s.base) exit(0);
   s.top=s.base;
   s.stacksize=STACK_INIT_SIZE;
   return s;
}

SqStack Push(SqStack s,type e)
{
   if(s.top-s.base>=s.stacksize)
   {
      s.base=(type *)realloc(s.base,(s.stacksize+STACK_ADD)*sizeof(type));
      if(!s.base) exit(0);
      s.top=s.base+s.stacksize;
      s.stacksize+=STACK_ADD;
   }
   *s.top++=e;
   return s;
}

SqStack Pop(SqStack s,type *e)
{
   if(s.top==s.base) exit(0);
   *e=*--s.top;
   return s;
}

SqStack StackTraverse(SqStack s)
{
   while(s.top!=s.base)
   {
      printf("%d",*--s.top);
   }

   printf("\n");
}

void conversion()
{
   SqStack s;
   int N;
   s=StackInit();
   printf("请输入待转换的数:"); scanf("%d",&N);
   while(N)
   {
      s=Push(s,N%8);
      N=N/8;
   }
   StackTraverse(s);
}

int main()
{
    conversion();

    return 0;
}
