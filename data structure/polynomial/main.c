#include <stdio.h>
#include <stdlib.h>

typedef int type;
typedef struct LNode
{
   type coef,exp;
   struct LNode *next;
}LNode,*LinkList;

LinkList PolyInit()
{
   LinkList head,p,q;
   int n,i;
   head=(LinkList)malloc(sizeof(LNode));
   if(head==NULL) {printf("Error!\n"); return NULL;}
   head->next=NULL;
   p=head;
   printf("请输入多项式项数:");
   scanf("%d",&n);
   for(i=0;i<n;i++)
   {
      q=(LinkList)malloc(sizeof(LNode));
      if(q==NULL) {printf("Error!\n"); return NULL;}
      printf("请输入系数:");
      scanf("%d",&q->coef);
      printf("请输入指数:");
      scanf("%d",&q->exp);
      q->next=NULL;
      p->next=q;    // !
      p=q;
   }
   return head;
}

void Output(LinkList head)
{
   LinkList p;
   p=head->next;
   while(p->next)
   {
      printf("%dx^",p->coef);
      printf("%d+",p->exp);
      p=p->next;
   }
   printf("%dx^",p->coef);
   printf("%d",p->exp);
   printf("\n");
}

LinkList PolySort(LinkList head)
{
   LinkList p,q;
   type temp1,temp2;
   for(p=head->next;p!=NULL;p=p->next)
   for(q=p->next;q!=NULL;q=q->next)
   {
      if(p->exp<q->exp)
      {
         temp1=p->exp;
         p->exp=q->exp;
         q->exp=temp1;
         temp2=p->coef;
         p->coef=q->coef;
         q->coef=temp2;
      }
   }
   return head;
}

LinkList PolyCombine(LinkList head)
{
   LinkList p,q;
   p=head->next;
   q=p->next;
   while(q)   //系数相加，其余项置0
   {
      if(p->exp==q->exp)
      {
         p->coef+=q->coef;
         q->coef=0;
         q=q->next;
      }
      else
      {
         p=q;
         q=q->next;
      }
   }
   //去掉系数0项
   p=head;
   q=p->next;
   while(q)
   {
      if(q->coef==0)
      {
         p->next=q->next;
         free(q);
      }
      p=p->next;
      q=p->next;
   }
   return head;
}

LinkList PolyAdd(LinkList la,LinkList lb)
{
   LinkList pa,pb,head,p;
   pa=la->next;
   pb=lb->next;
   head=(LinkList)malloc(sizeof(LNode));
   if(head==NULL) {printf("Error!\n"); return NULL;}
   head->next=NULL;
   p=head;

   while(pa && pb)
   {
      if(pa->exp>pb->exp)
      {
         p->next=pa;
         p=pa;
         pa=pa->next;
      }
      else if(pa->exp<pb->exp)
      {
         p->next=pb;
         p=pb;
         pb=pb->next;
      }
      else
      {
         pa->coef+=pb->coef;
         p->next=pa;
         p=pa;
         pa=pa->next;
         pb=pb->next;
      }
   }
   if(pa) p->next=pa;
   if(pb) p->next=pb;
   return head;
}

int main()
{
    LinkList la,lb,ladd;
    la=PolyInit();
    printf("la: "); Output(la);
    lb=PolyInit();
    printf("lb: "); Output(lb);
    la=PolySort(la);
    la=PolyCombine(la);
    printf("la: "); Output(la);
    lb=PolySort(lb);
    lb=PolyCombine(lb);
    printf("lb: "); Output(lb);
    ladd=PolyAdd(la,lb);
    Output(ladd);

    return 0;
}
