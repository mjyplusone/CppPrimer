//Input:ABC##DE#G##F###
//先：ABCDEGF
//中；CBEGDFA
//后：CGEFDBA
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
   s.base=(type *)malloc(STACK_INIT*sizeof(type));
   if(!s.base) exit(0);
   s.top=s.base;
   s.stacksize=STACK_INIT;
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
   if(s.top-s.base==0) exit(0);
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

void StackTraverse(SqStack s)
{
   while(s.top!=s.base)
      printf("%c ",*--s.top);
   printf("\n");
}

SqStack DestroyStack(SqStack s)
{
   if(!s.base) exit(0);
   free(s.base);
   return s;
}

SqStack ClearStack(SqStack s)
{
   if(!s.base) exit(0);
   s.top=s.base;
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

void PreOrderTraverse(BiTree T)
{
   SqStack s;
   type p;
   s=StackInit(); s=Push(s,T);
   while(!StackEmpty(s))
   {
      s=Pop(s,&p);
      printf("%c ",p->data);
      if(p->rchild) s=Push(s,p->rchild);
      if(p->lchild) s=Push(s,p->lchild);
   }
   printf("\n");
   DestroyStack(s);
}

void InOrderTraverse(BiTree T)
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

void PostOrderTraverse(BiTree T)
{
    SqStack s;
    type p,q;
    s=StackInit();      s=Push(s,T); // 根指针入栈
    while(!StackEmpty(s))
    {
        while((p=GetTop(s))&&p)   s=Push(s,p->lchild);    //向左走到尽头
        s=Pop(s,&p);     //空指针出栈
        p=GetTop(s);
        if(p->rchild)
        {
            s=Push(s,p->rchild);
            continue;
        }
        if(!StackEmpty(s))
        {//访问结点，向右一步
            s=Pop(s,&p);
            printf("%c ",p->data);
            while ((q=GetTop(s))&&q&&p==q->rchild)
            {//若当前为右子树，则继续出栈
                s=Pop(s,&p);
                printf("%c ",p->data);
            }
            p=GetTop(s);
            if(p->rchild)
            {
                s=Push(s,p->rchild);
                continue;
            }
            else
            {
                s=Pop(s,&p);
                printf("%c ",p->data);
            }
        }//if
    }//while
    DestroyStack(s);
}

int main()
{
   BiTree T;
   T=CreateTree();
   PreOrderTraverse(T);
   InOrderTraverse(T);
   PostOrderTraverse(T);

   return 0;
}
