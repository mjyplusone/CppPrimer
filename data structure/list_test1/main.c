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
   LNode *p,*q;
   int i;
   head=(LinkList)malloc(sizeof(LNode));
   if(head==NULL) {printf("Create fail!\n"); return NULL;}
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
   int i=0;
   LNode *p;
   p=head->next;
   while(p)
   {
      printf("%d ",p->data);
      p=p->next;
   }
   printf("\n");
}

LinkList DelInsert(LinkList la,LinkList lb,int i,int j,int len)
{
   LinkList pa,qa,prev,pb;
   int k=1;
   pa=la->next;
   while(pa && k<i)
   {
      prev=pa;
      pa=pa->next;
      ++k;
   }
   qa=pa;
   k=1;
   while(qa && k<len)
   {
      qa=qa->next;
      k++;
   }
   prev->next=qa->next;

   pb=lb->next;
   k=1;
   while(pb && k<j-1)
   {
      pb=pb->next;
      k++;
   }
   Output(la);
   qa->next->next=pb->next;
   pb->next=la->next;
   return lb;
}

int main()
{
    LNode *la,*lb;
    la=CreateList(la,5);
    lb=CreateList(lb,6);
    Output(la); Output(lb);
    lb=DelInsert(la,lb,2,3,3);
    Output(lb);
    return 0;
}
