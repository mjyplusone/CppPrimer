#include <stdio.h>
#include <stdlib.h>
#define STACK_INIT 100
#define STACK_ADD 10

typedef char type;
typedef struct
{
   type *base,*top;
   int stacksize;
}SqStack;

SqStack StackInit()
{
   SqStack s;
   s.base=(type*)malloc(STACK_INIT*sizeof(type));
   if(!s.base) exit(0);
   s.top=s.base;
   s.stacksize=STACK_INIT;
   return s;
}

SqStack Push(SqStack s,type e)
{
   if(s.top-s.base>=s.stacksize)
   {
      s.base=(type*)realloc(s.base,(s.stacksize+STACK_ADD)*sizeof(type));
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

void Traverse(SqStack s)
{
   while(s.top!=s.base)
      printf("%c ",*--s.top);
   printf("\n");
}

int Judge(char a[])
{
   SqStack s;
   type e;
   s=StackInit();
   int i=0;
   while(a[i]!='&' && a[i])
   {
      s=Push(s,a[i]);
      i++;
   }
   if(!a[i]) return 0;
   else i++;

   while(a[i])
   {
      s=Pop(s,&e);
      if(e!=a[i]) return 0;
      i++;
   }
   return 1;
}

int main()
{
   char buffer[100];
   int result;
   scanf("%s",&buffer);
   result=Judge(buffer);
   printf("result=%d\n",result);

   return 0;
}
