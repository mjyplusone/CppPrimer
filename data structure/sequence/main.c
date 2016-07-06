#include <stdio.h>
#include <stdlib.h>
#define initsize 100
#define addsize 10

typedef int type;
typedef struct
{
   type *data;
   int length;
   int listsize;
}sqlist;

sqlist InitList(sqlist L)
{
   L.data = (type*)malloc(initsize*sizeof(type));
   if(!L.data)  exit(0);
   L.length=0;
   L.listsize=initsize;
   return L;
}

sqlist InsertList(sqlist L,int i,type e)
{
   type *newbase,*p,*q;
   if(i<1 || i>L.length+1) printf("Error!");
   if(L.length>=L.listsize)
   {
      newbase=(type*)realloc(L.data,(L.listsize+addsize)*sizeof(type));
      if(!newbase) exit(0);
      L.data=newbase;
      L.listsize+=addsize;
   }
   q=&(L.data[i-1]);
   for(p=&(L.data[L.length-1]); p>=q; --p)
      *(p+1)=*p;
   *q=e;
   L.length++;
   return L;
}

sqlist DelList(sqlist L,int i,type e)
{
   type *p,*q;
   if(i<1 || i>L.length) printf("Error!");
   q=&(L.data[i-1]);
   e=*q;
   p=&(L.data[L.length-1]);
   for(;q<=p;++q)
      *q=*(q+1);
   --L.length;
   return L;
}

int Location(sqlist L,type e)
{
   int i=0;
   while(i<L.length && L.data[i]!=e)
      ++i;
   if(i<L.length)  return i+1;
   else return 0;
}

sqlist MergeList(sqlist la,sqlist lb,sqlist lc)
{
   type *pa,*pb,*pc,*pa_last,*pb_last;
   pa=la.data;
   pb=lb.data;
   lc.listsize=lc.length=la.length+lb.length;
   pc=lc.data=(type*)malloc(lc.listsize*sizeof(type));
   if(!lc.data) exit(0);
   pa_last=la.data+la.length-1;
   pb_last=lb.data+lb.length-1;
   while(pa<=pa_last && pb<pb_last)
   {
      if(*pa<*pb) *pc++=*pa++;
      else        *pc++=*pb++;
   }
   while(pa<=pa_last) *pc++=*pa++;
   while(pb<=pb_last) *pc++=*pb++;
   return lc;
}

void Output(sqlist L)
{
   int i=0;
   if(L.length<=0)  printf("empty!\n");
   for(i=0;i<L.length;i++)
      printf("%d ",L.data[i]);
   printf("\n");
}

int main()
{
   sqlist la,lb,lc;
   type e;
   int i,loc;
   la=InitList(la); lb=InitList(lb);
   for(i=0;i<5;i++)
   {
      la=InsertList(la,i+1,i);
      lb=InsertList(lb,i+1,i+2);
   }
   la=DelList(la,1,e);
   lc=MergeList(la,lb,lc);

   Output(la); Output(lb); Output(lc);

   loc=Location(lc,6);
   printf("%d\n",loc);

   return 0;
}
