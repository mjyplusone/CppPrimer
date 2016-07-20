#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Num
{
   char str[1000];
   int len;
}Num;

int cmp(const void *a,const void *b)  // !
{
   Num *c=(Num*)a;
   Num *d=(Num*)b;
   if(c->len!=d->len) return (c->len-d->len);
   else return strcmp(c->str,d->str);
}

int main()
{
   int N,i,j;
   Num data[100],temp;
   while(scanf("%d",&N)!=EOF && (N>=1 && N<=100))
   {
      for(i=0;i<N;i++)
      {
         scanf("%s",&data[i].str);
         data[i].len=strlen(data[i].str);
      }
      //qsort(data,N,sizeof(Num),cmp);
      //如果不用qsort
      for(i=0;i<N;i++)
      for(j=i+1;j<N;j++)
      {
         if(data[i].len>data[j].len)
         {
            temp=data[i];
            data[i]=data[j];
            data[j]=temp;
         }
         else if(data[i].len==data[j].len && strcmp(data[i].str,data[j].str)>0)
         {
            temp=data[i];
            data[i]=data[j];
            data[j]=temp;
         }
      }

      for(i=0;i<N;i++)
         printf("%s\n",data[i].str);
   }

   return 0;
}
