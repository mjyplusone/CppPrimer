#include <stdio.h>
#include <stdlib.h>

typedef int type;
typedef struct DulNode
{
   type data;
   struct DulNode *prior;
   struct DulNode *next;
}DulNode, *DuLinkList;

DuLinkList CreateList()
{
   DuLinkList p,q,head;
   type x;
   head=(DuLinkList)malloc(sizeof(DulNode));
   if(head==NULL) {printf("Error!\n"); return NULL;}
   p=head;
   p->next = NULL;
   printf("Please input data: \n");
   while(scanf("%d",&x) && x!=0)
   {
      q=(DuLinkList)malloc(sizeof(DulNode));
      if(q==NULL) {printf("Error!\n"); return NULL;}
      q->data=x;
      q->next=NULL;
      q->prior=p;
      p->next=q;
      p=q;
   }
   return head;
}

void Output(DuLinkList head)
{
   DuLinkList p;
   p=head->next;
   while(p)
   {
      printf("%d ",p->data);
      p=p->next;
   }
   printf("\n");
}

DuLinkList ListInsert(DuLinkList head,int i,type e)
{
   DuLinkList p,q;
   int j=1;
   p=head;
   while(p && j<i)
   {
      p=p->next;
      ++j;
   }
   if(!p || j>i) printf("Error!\n");
   q=(DuLinkList)malloc(sizeof(DulNode));
   q->data=e;
   q->next=p->next;
   p->next=q;
   p=q->prior;
   return head;
}

//注意！之前写的delete和insert均有问题，要考虑头尾元素情况！！！
// !!!
DuLinkList ListDel(DuLinkList head,int i,type *e)
{
   DuLinkList p,q;
   int j=1;
   p=head;
   while(p && j<i)
   {
      p=p->next;
      ++j;
   }
   q=p->next;
   if(q->next==NULL)
   {
      *e=q->data;
      free(q);
      p->next=NULL;
   }
   else
   {
      p->next=q->next;
      q->next->prior=p;
      *e=q->data;
      free(q);
   }
   return head;
}

DuLinkList ListSort(DuLinkList head)
{
   DuLinkList p,q;
   type temp;
   for(p=head->next;p!=NULL;p=p->next)
   {
      for(q=p->next;q!=NULL;q=q->next)
      {
         if(p->data>q->data)
         {
            temp=p->data;
            p->data=q->data;
            q->data=temp;
         }
      }
   }
   return head;
}

int main()
{
    DuLinkList la,lb;
    type e;
    la=CreateList();
    Output(la);
    la=ListSort(la);
    Output(la);
    return 0;
}
