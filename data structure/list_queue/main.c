#include <stdio.h>
#include <stdlib.h>

typedef int type;

typedef struct QNode
{
   type data;
   struct QNode *next;
}QNode,*QueuePtr;

typedef struct
{
   QueuePtr front;
   QueuePtr rear;
}LQueue;

LQueue QueueInit()
{
   LQueue Q;
   Q.front=Q.rear=(QueuePtr)malloc(sizeof(QNode));
   if(!Q.front) exit(0);
   Q.front->next=NULL;
   return Q;
}

LQueue QueueDestroy(LQueue Q)
{
   while(Q.front)
   {
      Q.rear=Q.front->next;
      free(Q.front);
      Q.front=Q.rear;
   }
   return Q;
}

LQueue EnQueue(LQueue Q,type e)
{
   QueuePtr p;
   p=(QueuePtr)malloc(sizeof(QNode));
   if(!p) exit(0);
   p->data=e;
   p->next=NULL;
   Q.rear->next=p;
   Q.rear=p;
   return Q;
}

LQueue DeQueue(LQueue Q,type *e)
{
   QueuePtr p;
   if(Q.rear==Q.front) exit(0);
   p=Q.front->next;
   *e=p->data;
   Q.front->next=p->next;
   if(Q.rear==p) Q.rear=Q.front;   // !!!
   free(p);
   return Q;
}

void Traverse(LQueue Q)
{
   QueuePtr p;
   p=Q.front->next;
   while(p!=Q.rear->next)
   {
      printf("%d ",p->data);
      p=p->next;
   }
   printf("\n");
}

int main()
{
   LQueue Q;
   type e;
   Q=QueueInit();
   Q=EnQueue(Q,1); Q=EnQueue(Q,2); Q=EnQueue(Q,3);
   Traverse(Q);
   Q=DeQueue(Q,&e);
   Traverse(Q);

   return 0;
}
