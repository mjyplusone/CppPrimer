#include <stdio.h>
#include <stdlib.h>

typedef char type;
typedef struct BiTNode
{
   type data;
   struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;

BiTree CreateTree()
{
   char ch;
   BiTree T;
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
   if(T)
   {
      printf("%c ",T->data);
      PreOrderTraverse(T->lchild);
      PreOrderTraverse(T->rchild);
   }
}

void InOrderTraverse(BiTree T)
{
   if(T)
   {
      InOrderTraverse(T->lchild);
      printf("%c ",T->data);
      InOrderTraverse(T->rchild);
   }
}

void PostOrderTraverse(BiTree T)
{
   if(T)
   {
      PostOrderTraverse(T->lchild);
      PostOrderTraverse(T->rchild);
      printf("%c ",T->data);
   }
}

int main()
{
   BiTree T;
   T=CreateTree();
   PreOrderTraverse(T);

   return 0;
}
