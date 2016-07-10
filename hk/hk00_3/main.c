#include <stdio.h>
#include <stdlib.h>

typedef int type;
typedef struct LNode
{
   type data;
   struct LNode *next;
}LNode,*LinkList;

LinkList CreateList(int n)
{
   LinkList head,p,q;
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

LinkList Sort(LinkList head)
{
   LinkList p,q;
   type temp;
   for(p=head->next;p!=NULL;p=p->next)
   for(q=p->next;q!=NULL;q=q->next)
   if(p->data>q->data)
   {
      temp=p->data;
      p->data=q->data;
      q->data=temp;
   }
   return head;
}

int main()
{
    LinkList la;
    int n;
    while(scanf("%d",&n)!=EOF)
    {
       la=CreateList(n);
       la=Sort(la);
       Output(la);
    }

    return 0;
}
