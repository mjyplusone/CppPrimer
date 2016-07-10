#include <stdio.h>
#include <stdlib.h>

typedef int type;
typedef struct LNode
{
   type data;
   struct LNode *next;
}LNode,*LinkList;

//Ñ­»·Á´±í
LinkList CreateList(LinkList head,int n)
{
   LinkList p,q;
   int i;
   head=(LinkList)malloc(sizeof(LNode));
   if(head==NULL) {printf("Error!\n"); return NULL;}
   head->next=NULL;
   p=head;
   for(i=0;i<n;i++)
   {
      q=(LinkList)malloc(sizeof(LNode));
      if(q==NULL) {printf("Error!\n"); return NULL;}
      scanf("%d",&q->data);
      q->next=NULL;
      p->next=q;
      p=q;
   }
   p->next=head;
   return head;
}

void Output(LinkList head)
{
   LinkList p;
   p=head->next;
   while(p!=head)
   {
      printf("%d ",p->data);
      p=p->next;
   }
   printf("\n");
}

type GetElem(LinkList head,int i,type e)
{
   LinkList p;
   int j=0;
   p=head;
   while(j<i)
   {
      p=p->next;
      ++j;
   }
   if(p==head || j>i) printf("Error!\n");
   e=p->data;
   return e;
}

int main()
{
    LinkList la,lb;
    type e;
    la=CreateList(la,5);
    Output(la);
    e=GetElem(la,3,e);
    printf("%d\n",e);
    return 0;
}
