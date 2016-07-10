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

LinkList Merge1(LinkList la,LinkList lb,LinkList lc)
{
   LinkList pa,pb,pc,qa,qb;
   pa=la->next;
   pb=lb->next;
   lc=pc=la;
   while(pa && pb)
   {
      qa=pa; qb=pb;
      pa=pa->next;
      pb=pb->next;
      qb->next=qa->next;
      qa->next=qb;
   }
   qb->next=pa?pa:pb;
   free(lb);
   return lc;
}

LinkList Merge2(LinkList la,LinkList lb,LinkList lc)
{
   LinkList pa,pb,qa,qb;
   pa=la->next;
   pb=lb->next;
   la->next=NULL;      //!!!
   lc=la;
   while(pa && pb)
   {
      if(pa->data<pb->data)
      {
         qa=pa;
         pa=pa->next;
         qa->next=la->next;
         la->next=qa;
      }
      else
      {
         qb=pb;
         pb=pb->next;
         qb->next=la->next;
         la->next=qb;
      }
   }
   while(pa)
   {
      qa=pa;
      pa=pa->next;
      qa->next=la->next;
      la->next=qa;
   }
   while(pb)
   {
      qb=pb;
      pb=pb->next;
      qb->next=la->next;
      la->next=qb;
   }
   free(lb);
   return lc;
}

LinkList Merge3(LinkList la,LinkList lb,LinkList lc)
{
   LinkList pa,pb,pc;
   pa=la->next;
   pb=lb->next;
   lc=pc=la;
   while(pa && pb)
   {
      if(pa->data<pb->data)
      {
         pc->next=pa;
         pc=pa;
         pa=pa->next;
      }
      else
      {
         pc->next=pb;
         pc=pb;
         pb=pb->next;
      }
   }
   pc->next=pa?pa:pb;
   free(lb);
   return lc;
}

LinkList Del(LinkList head)  //在3的基础上去掉重复元素
{
   LinkList p,prev,q;
   p=head;
   prev=p;
   p=p->next;
   while(p)
   {
      prev=p;
      p=p->next;
      if(p && prev->data==p->data)
      {
         prev->next=p->next;
         q=p;
         p=p->next;
         free(q);
      }
   }
   return head;
}

//------------------------------------------------------
//A-(B交C)
//------------------------------------------------------
LinkList Cross(LinkList lb,LinkList lc,LinkList l)
{
   LinkList head,p,prev,q,qa;
   head=Merge3(lb,lc,head);
   p=head;
   prev=p;
   p=p->next;
   q=l;
   while(p)
   {
      prev=p;
      p=p->next;
      if(p && prev->data==p->data)
      {
         qa=(LinkList)malloc(sizeof(LNode));
         if(qa==NULL) {printf("Error!\n"); return NULL;}
         qa->data=prev->data;
         qa->next=NULL;
         l->next=qa;
         l=qa;
      }
   }
   return q;
}

LinkList Minus(LinkList la,LinkList lb)
{
   LinkList pa,pb,q,prev;
   pa=la->next;
   pb=lb->next;

   while(pa && pb)
   {
      if(pa->data<pb->data)
      {
         prev=pa;
         pa=pa->next;
      }
      else if(pa->data>pb->data)
      {
         pb=pb->next;
      }
      else
      {
         prev->next=pa->next;
         q=pa;
         pa=pa->next;
         free(q);
      }
   }
   return la;
}

LinkList Merge4(LinkList la,LinkList lb,LinkList lc)
{
   LinkList l,lbc;
   l=CreateList(l,0);
   lbc=Cross(lb,lc,l);
   la=Minus(la,lbc);
   return la;
}
//----------------------------------------------------

int main()
{
   LinkList la,lb,lc,l;
   la=CreateList(la,7);
   lb=CreateList(lb,8);
   lc=CreateList(lc,8);
   Output(la); Output(lb);
   la=Merge4(la,lb,lc);
   Output(la);
   return 0;
}
