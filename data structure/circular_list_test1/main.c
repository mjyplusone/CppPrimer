//数据结构习题集2.33
#include <stdio.h>
#include <stdlib.h>

typedef char type;
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
      scanf("%c",&q->data);
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
      printf("%c ",p->data);
      p=p->next;
   }
   printf("\n");
}

LinkList CreateList2(int n)
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
      scanf("%c",q->data);
      q->next=NULL;
      p->next=q;
      p=q;
   }
   p->next=head;
}

void Output2(LinkList head)
{
   LinkList p;
   p=head->next;
   while(p!=head)
   {
      printf("%c ",p->data);
      p=p->next;
   }
   printf("\n");
}

void Divide(LinkList l,LinkList la,LinkList lb,LinkList lc)
{
   LinkList p,pa,pb,pc,q;
   p=l->next;
   pa=la; pb=lb; pc=lc;
   while(p)
   {
      if(p->data>='0' && p->data<='9')
      {
         q=p;
         p=p->next;
         q->next=pa->next;
         pa->next=q;
         pa=pa->next;
      }
      else if((p->data>='A' && p->data<='Z') || (p->data>='a' &&p->data<='z'))
      {
         q=p;
         p=p->next;
         q->next=pb->next;
         pb->next=q;
         pb=pb->next;
      }
      else
      {
         q=p;
         p=p->next;
         q->next=pc->next;
         pc->next=q;
         pc=pc->next;
      }
   }
   free(l);
   Output2(la); Output2(lb); Output2(lc);
}

int main()
{
    LinkList l,la,lb,lc;
    l=CreateList(7);
    la=CreateList2(0); lb=CreateList2(0); lc=CreateList2(0);
    Output(l);
    Divide(l,la,lb,lc);

    return 0;
}
