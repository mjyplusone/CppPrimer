//ÐÐ±à¼­³ÌÐò
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

SqStack Pop(SqStack s,type e)
{
   if(s.top==s.base) exit(0);
   e=*--s.top;
   return s;
}

SqStack Traverse(SqStack s)
{
   SqStack result;
   result=StackInit();
   while(s.top!=s.base)
      //printf("%c",*--s.top);
      result=Push(result,*--s.top);
   while(result.top!=result.base)
      printf("%c",*--result.top);
   printf("\n");
}

SqStack Clear(SqStack s)
{
   while(s.top!=s.base)
      --s.top;
   return s;
}

SqStack Destroy(SqStack s)
{
   free(s.base);
   s.base=NULL; s.top=NULL;
   s.stacksize=0;
   return s;
}

void LineEdit()
{
   SqStack s;
   char ch;
   s=StackInit();
   ch=getchar();
   while(ch!=EOF)
   {
      while(ch!='\n')
      {
         switch(ch)
         {
            case '#':s=Pop(s,ch); break;
            case '@':s=Clear(s); break;
            default:s=Push(s,ch); break;
         }
         ch=getchar();
      }
      Traverse(s);
      s=Clear(s);
      ch=getchar();
   }
   s=Destroy(s);
}

int main()
{
   LineEdit();
   return 0;
}
