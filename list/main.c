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
   int i;
   LinkList p,q;
   head=(LinkList)malloc(sizeof(LNode));
   if(head==NULL)
   {
      printf("Create Error!\n");
      return NULL;
   }
   head->next=NULL;
   p=head;
   for(i=0;i<n;i++)
   {
      q=(LinkList)malloc(sizeof(LNode));
      if(q==NULL) {printf("ERROR!\n"); return NULL;}
      scanf("%d",&q->data);
      q->next=NULL;
      p->next=q;
      p=q;
   }
   return head;
}

void Output(LNode *head)
{
   LNode *p;
   for(p=head->next;p!=NULL;)
   {
      printf("%d ",p->data);
      p=p->next;
   }
   printf("\n");
}

LinkList InsertList(LinkList head,int i,type e)
{
   LNode *p,*q;
   int j=1;
   p=head->next;
   while(p&&j<i-1)    //寻找第i-1个节点
   {
      p=p->next;
      ++j;
   }
   if(!p || j>i-1) printf("Error!\n");
   q=(LinkList)malloc(sizeof(LNode));
   q->data=e;
   q->next=p->next;
   p->next=q;
   return head;
}

LinkList DelList(LinkList head,int i,type *e)
{
   LNode *p,*q;
   int j=1;
   p=head->next;
   while(p&&j<i-1)
   {
      p=p->next;
      ++j;
   }
   if(!(p->next) || j>i-1) printf("Error!\n");
   q=p->next;
   p->next=q->next;
   *e=q->data;
   free(q);
   return head;
}

type GetElem(LinkList head,int i,type e)
{
   LNode *p;
   int j=1;
   p=head->next;
   while(p && j<i)
   {
      p=p->next;
      ++j;
   }
   if(!p || j>i) printf("Error!\n");
   e=p->data;
   return e;
}

int Location(LinkList head,type e)
{
   LNode *p;
   int i=1;
   p=head->next;
   while(p && p->data!=e)
   {
      p=p->next;
      ++i;
   }
   return i;
}

LinkList MergeList(LinkList la,LinkList lb,LinkList lc)
{
   LNode *pa,*pb,*pc;
   pa=la->next; pb=lb->next;
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

int LengthList(LinkList head)
{
   LNode *p;
   int i=0;
   p=head->next;
   while(p)
   {
      p=p->next;
      ++i;
   }
   return i;
}

int main()
{
    LNode *la,*lb,*lc;
    type elem;
    int loc,len;
    la=CreateList(la,5);
    lb=CreateList(lb,6);
    InsertList(la,3,100);
    Output(la);
    Output(lb);
    DelList(la,3,&elem);
    Output(la);
    printf("%d\n",elem);
    elem=GetElem(la,2,elem);
    printf("%d\n",elem);
    lc=MergeList(la,lb,lc);
    Output(lc);
    loc=Location(lc,7);
    printf("%d\n",loc);
    len=LengthList(lc);
    printf("%d\n",len);
    return 0;
}
