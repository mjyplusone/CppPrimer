#include <stdio.h>
#include <stdlib.h>
#define STACK_INIT_SIZE 100
#define STACK_ADD 10

typedef int type;
typedef struct
{
   type *base;
   type *top;
   int stacksize;
}SqStack;

SqStack InitStack()
{
   SqStack s;
   s.base=(type*)malloc(STACK_INIT_SIZE*sizeof(type));
   if(!s.base) exit(0);
   s.top=s.base;
   s.stacksize=STACK_INIT_SIZE;
   return s;
}

SqStack Push(SqStack s,type e)
{
   if(s.top-s.base>=s.stacksize)  //stack full
   {
      s.base=(type *)realloc(s.base,(s.stacksize+STACK_ADD)*sizeof(type));
      if(!s.base) exit(0);
      s.top=s.base+s.stacksize;
      s.stacksize+=STACK_ADD;   //?
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

type GetTop(SqStack s)
{
   type e;
   if(s.top==s.base) exit(0);
   e=*(s.top-1);
   return e;
}

int StackLength(SqStack s)
{
   return (s.top-s.base);
}

SqStack StackTraverse(SqStack s)
{
   while(s.top!=s.base)
      printf("%d ",*--s.top);
   printf("\n");
}

int main()
{
    SqStack s;
    type e;int len;
    s=InitStack();
    s=Push(s,2);s=Push(s,3);s=Push(s,1);
    StackTraverse(s);
    s=Pop(s,&e);
    StackTraverse(s);
    printf("%d\n",e);
    e=GetTop(s);
    printf("%d\n",e);
    len=StackLength(s);
    printf("%d\n",len);

    return 0;
}
