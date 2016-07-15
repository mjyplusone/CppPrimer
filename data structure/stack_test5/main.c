//Ex3.16
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
      printf("%c",*--s.top);
   printf("\n");
}

int main()
{
   SqStack s;
   char buffer[100],buffer1[100];
   int i=0,j=0;
   s=StackInit(s);
   scanf("%s",&buffer);
   while(buffer[i])
   {
      if(buffer[i]=='S')
      {
         buffer1[j]=buffer[i];
         j++;
      }
      else
         s=Push(s,buffer[i]);
      i++;
   }
   while(s.top!=s.base)
   {
      s=Pop(s,&buffer1[j]);
      j++;
   }

   printf("%s\n",buffer1);

   return 0;
}
