//转换为逆波兰表达式，所有表达式的输入为#...#
//操作数入栈；遇到操作符时，操作数出栈，求值，将结果入栈；当一遍后，栈顶就是表达式的值。
#include <stdio.h>
#include <stdlib.h>
#define STACK_INIT_SIZE 100
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
      printf("%c",*--s.top);
   printf("\n");
}

int StackEmpty(SqStack s)
{
   if(s.top==s.base) return 1;
   else return 0;
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

void Bolan(char buffer[])
{
   SqStack s;
   type e;
   char compare;
   char result[100];
   int i=0,j=0;
   s=InitStack();
   s=Push(s,buffer[i]);
   i++;
   while(buffer[i]!='#')
   {
      if(buffer[i]>='0' && buffer[i]<='9')
      {
         result[j]=buffer[i];
         i++;j++;
      }
      else
      {
         e=GetTop(s);
         compare=Precede(buffer[i],e);
         if(compare=='>')
         {
            s=Push(s,buffer[i]);
            i++;
         }
         else
         {
            s=Pop(s,&e);
            result[j]=e;
            j++;
         }
      }
   }
   while(s.top!=s.base)
   {
      s=Pop(s,&e);
      result[j]=e;
      j++;
   }
   j=0;
   while(result[j]!='#')
   {
      printf("%c",result[j]);
      j++;
   }
}

int main()
{
    char buffer[100];
    scanf("%s",buffer);
    Bolan(buffer);

    return 0;
}
