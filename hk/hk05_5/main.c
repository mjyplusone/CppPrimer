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
   BiTree T;
   char ch;
   scanf("%c",&ch);
   if(ch=='0') T=NULL;
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

void InOrderTraverse(BiTree T)
{
   if(T)
   {
      InOrderTraverse(T->lchild);
      printf("%c ",T->data);
      free(T);
      InOrderTraverse(T->rchild);
   }
}

int main()
{
    BiTree T;
    T=CreateTree();
    InOrderTraverse(T);

    return 0;
}
