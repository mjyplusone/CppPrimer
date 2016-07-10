//数据结构习题集2.38
#include <stdio.h>
#include <stdlib.h>

typedef int type;
typedef struct LNode
{
   type data;
   struct LNode *prior,*next;
   int fre;
}LNode,*LinkList;

//双向循环链表
LinkList CreateList(int n)
{
   LinkList head,p,q;
   int i;
   head=(LinkList)malloc(sizeof(LNode));
   if(head==NULL) {printf("Error!"); return NULL;}
   head->next=NULL;
   p=head;
   for(i=0;i<n;i++)
   {
      q=(LinkList)malloc(sizeof(LNode));
      if(q==NULL) {printf("Error!\n"); return NULL;}
      scanf("%d",&q->data);
      q->fre=0;
      q->next=NULL;
      q->prior=p;
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
      printf("%d-%d ",p->data,p->fre);
      p=p->next;
   }
   printf("\n");
}

int Location_Sort(LinkList head,type e)
{
   LinkList p,q;
   int i=1;
   p=head->next;
   while(p!=head && p->data!=e)
   {
      ++i;
      p=p->next;
   }
   p->fre++;
   p->prior->next=p->next;
   p->next->prior=p->prior;

   q=head->next;
   while(q!=head && q->fre>p->fre)
      q=q->next;

   p->next=q->prior->next;
   q->prior->next=p;
   p->prior=q->prior;
   q->prior=p;

   return head;
}

int main()
{
    LinkList la,lb;
    int loc;
    la=CreateList(7);
    Output(la);
    loc=Location_Sort(la,1);
    Output(la);
    loc=Location_Sort(la,7);
    Output(la);
    loc=Location_Sort(la,3);
    Output(la);
    loc=Location_Sort(la,1);
    Output(la);

    return 0;
}
