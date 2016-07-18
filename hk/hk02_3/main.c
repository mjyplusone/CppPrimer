#include <stdio.h>
#include <stdlib.h>
#define STACK_INIT 100
#define STACK_ADD 10

typedef struct BiTNode
{
   char data;
   struct BiTNode *lchild,*rchild;
   int flag;   //右子树是否被访问过标志位
}BiTNode,*BiTree;

typedef BiTree type;

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
   if(s.top-s.base==0) exit(0);
   *e=*--s.top;
   return s;
}

SqStack DestroyStack(SqStack s)
{
   if(!s.base) exit(0);
   free(s.base);
   return s;
}

int StackEmpty(SqStack s)
{
   if(s.top==s.base) return 1;
   else return 0;
}

BiTree CreateTree()
{
   BiTree T;
   char ch;
   scanf("%c",&ch);
   if(ch=='#') T=NULL;
   else
   {
      T=(BiTree)malloc(sizeof(BiTNode));
      if(!T) exit(0);
      T->data=ch;
      T->lchild=CreateTree();
      T->rchild=CreateTree();
   }
   return T;
}

void InOrdertraverse(BiTree T)
{
   if(T)
   {
      InOrdertraverse(T->lchild);
      printf("%c ",T->data);
      InOrdertraverse(T->rchild);
   }
}

void InOrderNotRecurssion(BiTree T)
{
   SqStack s;
   type p;
   s=StackInit(); p=T;
   while(p || !StackEmpty(s))
   {
      if(p)
      {
         s=Push(s,p); p=p->lchild;
      }
      else
      {
         s=Pop(s,&p);
         printf("%c ",p->data);
         p=p->rchild;
      }
   }
   printf("\n");
   DestroyStack(s);
}

int main()
{
   BiTree T;
   T=CreateTree();
   InOrdertraverse(T);
   InOrderNotRecurssion(T);

   return 0;
}
