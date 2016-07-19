#include <stdio.h>
#include <stdlib.h>

typedef struct BiTNode
{
   int data;
   struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;

BiTree BSTInsert(BiTree T,int value)
{
   BiTree node;
   if(T==NULL)
   {
      node=(BiTree)malloc(sizeof(BiTNode));
      node->data=value;
      node->lchild=node->rchild=NULL;
      T=node;
   }
   else if(value<T->data)
      T->lchild=BSTInsert(T->lchild,value);
   else if(value>T->data)
      T->rchild=BSTInsert(T->rchild,value);
   //遇到重复元素，不插入，什么都不做!

   return T;
}

/*
BiTree CreateBST(int a[],int N)
{
   BiTree T;
   int i;
   for(i=0;i<N;i++)
      T=BSTInsert(T,a[i]);
   return T;
}
*/

void PreOrderTraverse(BiTree T)
{
   if(T)
   {
      printf("%d ",T->data);
      PreOrderTraverse(T->lchild);
      PreOrderTraverse(T->rchild);
   }
}

void InOrderTraverse(BiTree T)
{
   if(T)
   {
      InOrderTraverse(T->lchild);
      printf("%d ",T->data);
      InOrderTraverse(T->rchild);
   }
}

void PostOrderTraverse(BiTree T)
{
   if(T)
   {
      PostOrderTraverse(T->lchild);
      PostOrderTraverse(T->rchild);
      printf("%d ",T->data);
   }
}

int main()
{
    BiTree T=NULL;   // 初始化为NULL！
    int i,N,value;
    while(scanf("%d",&N)!=EOF)
    {
       for(i=0;i<N;i++)
       {
          scanf("%d",&value);
          T=BSTInsert(T,value);
       }
       PreOrderTraverse(T); printf("\n");
       InOrderTraverse(T); printf("\n");
       PostOrderTraverse(T); printf("\n");
    }

   return 0;
}
