#include <stdio.h>
#include <stdlib.h>

typedef int type;
typedef struct LNode
{
   type data;
   struct LNode *next;
}LNode,*LinkList;

LinkList CreateList()
{
   LinkList head,p,q;
   type e;
   head=(LinkList)malloc(sizeof(LNode));
   if(head==NULL) {printf("Error!\n"); exit(0);}
   head->next=NULL;
   p=head;
   while(scanf("%d",&e) && e!=0)
   {
      q=(LinkList)malloc(sizeof(LNode));
      if(q==NULL) {printf("Error!\n"); exit(0);}
      q->data=e;
      q->next=NULL;
      p->next=q;
      p=q;
   }
   return head;
}

int Max(LinkList head)
{
   LinkList p,q;
   int max=1,i=1;
   p=head->next;  //max
   q=p->next;  //cur
   while(q)
   {
      i++;
      if(q->data>p->data)
      {
         p=q;
         max=i;
      }
      q=q->next;
   }
   return max;
}

int main()
{
    LinkList p;
    int maxpos;
    p=CreateList();
    maxpos=Max(p);
    printf("%d\n",maxpos);

    return 0;
}
