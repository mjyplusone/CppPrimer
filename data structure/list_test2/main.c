#include <stdio.h>
#include <stdlib.h>

typedef int type;
typedef struct LNode
{
   type data;
   struct LNode *next;
}LNode,*LinkList;

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
   return head;
}

void Output(LinkList head)
{
   LinkList p;
   p=head->next;
   while(p)
   {
      printf("%d ",p->data);
      p=p->next;
   }
   printf("\n");
}

LinkList del(LinkList head,type min,type max)
{
   LinkList p,prev,q;
   p=head->next;
   while(p && p->data<min)
   {
      prev=p;
      p=p->next;
   }
   while(p && p->data<=max)
   {
      p=p->next;
   }
   while(prev->next!=p)
   {
      q=prev->next;
      prev->next=q->next;
      free(q);
   }
   return head;
}

int main()
{
    LinkList la;
    la=CreateList(la,5);
    Output(la);
    la=del(la,2,4);
    Output(la);

    return 0;
}
