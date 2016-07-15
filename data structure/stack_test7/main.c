//3.19¿®∫≈∆•≈‰
#include <stdio.h>
#include <stdlib.h>
#define STACK_INIT_SIZE 100
#define STACK_ADD 10

typedef char type;
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

int bracket(char buffer[])
{
   SqStack s;
   type e;
   int i=0;
   s=InitStack();
   while(buffer[i])
   {
      if(buffer[i]=='(' || buffer[i]=='[')
         s=Push(s,buffer[i]);
      else if(buffer[i]==')' || buffer[i]==']')
      {
         s=Pop(s,&e);
         if(e==buffer[i]) return 0;
      }
      i++;
   }
   return 1;
}

int main()
{
   char buffer[100];
   int result;
   scanf("%s",&buffer);
   result=bracket(buffer);
   printf("%d\n",result);

   return 0;
}
