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
   if(head==NULL) {printf("Error!\n"); exit(0);}
   head->next=NULL;
   p=head;
   for(i=0;i<n;i++)
   {
      q=(LinkList)malloc(sizeof(LNode));
      if(q==NULL) {printf("Error!\n"); exit(0);}
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

LinkList InsertList(LinkList head,int i,type e)
{
   LinkList p,q;
   int j=1;
   p=head->next;
   while(p && j<i-1)
   {
      p=p->next;
      ++j;
   }
   if(!p || j>i-1) {printf("Error!\n"); exit(0);}
   q=(LinkList)malloc(sizeof(LNode));
   q->data=e;
   q->next=p->next;
   p->next=q;
   return head;
}

LinkList DelList(LinkList head,int i,type *e)
{
   LinkList p,q;
   int j=1;
   p=head->next;
   while(p && j<i-1)
   {
      p=p->next;
      ++j;
   }
   if(!(p->next || j>i-1)) {printf("Error!\n"); exit(0);}
   q=p->next;
   p->next=q->next;
   *e=q->data;
   free(q);
   return head;
}

LinkList Sort(LinkList head)
{
   LinkList p,q;
   type temp;
   for(p=head->next;p!=NULL;p=p->next)
   for(q=p->next;q!=NULL;q=q->next)
   {
      if(p->data>q->data)
      {
         temp=p->data;
         p->data=q->data;
         q->data=temp;
      }
   }
   return head;
}

int Sum(LinkList head)
{
   LinkList p;
   int sum=0;
   p=head->next;
   while(p)
   {
      sum+=p->data;
      p=p->next;
   }
   return sum;
}

int main()
{
    LinkList p,q;
    int sum;
    p=CreateList(5);
    Output(p);
    p=Sort(p);
    Output(p);
    sum=Sum(p);
    printf("%d\n",sum);

    return 0;
}
