#include <stdio.h>
#include <stdlib.h>

typedef int type;

typedef struct LNode
{
   type data;
   struct LNode *next;
}LNode,*LinkList;

typedef struct LStack
{
   LinkList top;
   int size;
}LStack;

void StackInit(LStack *s)
{
   LinkList p;
   p=(LinkList)malloc(sizeof(LNode));
   if(p==NULL) {printf("Error!\n"); return NULL;}
   s->top=p;
   p->next=NULL;
   s->size=0;
}

void StackDestroy(LStack *s)
{
   LinkList p;
   p=s->top;
   while(p)
   {
      s->top=p->next;
      free(p);
      p=s->top;
   }
   s->size=0;
}

int StackLength(LStack s)
{
   return s.size;
}

int StackEmpty(LStack s)
{
   if(s.size==0) return 1;
   else return 0;
}

type GetTop(LStack s,type *e)
{
   if(!s.top) return 0;
   *e=s.top->data;
}

void Push(LStack *s,type e)
{
   LinkList p;
   p=(LinkList)malloc(sizeof(LNode));
   if(p==NULL) {printf("Error!\n"); return NULL;}
   p->data=e;
   p->next=s->top;
   s->top=p;
   s->size++;
}

void Pop(LStack *s,type *e)
{
   LinkList p;
   if(!(s->top)) exit(0);
   *e=s->top->data;
   p=s->top;
   s->top=p->next;
   free(p);
   s->size--;
}

void Traverse(LStack *s)
{
   LinkList p;
   if(!s->top) exit(0);
   p=s->top;
   while(p->next)   // !
   {
      printf("%d ",p->data);
      p=p->next;
   }
   printf("\n");
}

int main()
{
    LStack s;
    type e; int len,Isempty;
    StackInit(&s);
    Push(&s,1); Push(&s,2); Push(&s,3);
    Traverse(&s);
    Pop(&s,&e);
    Traverse(&s);
    printf("%d\n",e);
    GetTop(s,&e);
    printf("%d\n",e);
    len=StackLength(s);
    printf("len=%d\n",len);
    Isempty=StackEmpty(s);
    printf("IsEmpty=%d\n",Isempty);

    return 0;
}
