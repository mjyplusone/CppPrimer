#include <stdio.h>
#include <stdlib.h>

void quicksort(int *a,int left,int right)
{
   if(left>=right) return 0;
   int i=left;
   int j=right;
   int key=a[left];

   while(i<j)
   {
      while(i<j && key<=a[j])
         j--;
      a[i]=a[j];
      while(i<j && key>=a[i])
         i++;
      a[j]=a[i];
   }
   a[i]=key;
   quicksort(a,left,i-1);
   quicksort(a,i+1,right);
}

int main()
{
   int N,i;
   int *a;
   while(scanf("%d",&N)!=EOF)
   {
      a=(int*)malloc(sizeof(int));
      for(i=0;i<N;i++)
      {
         scanf("%d",&a[i]);
      }
      quicksort(a,0,N-1);
      for(i=0;i<N;i++)
         printf("%d ",a[i]);
      printf("\n");
   }
   return 0;
}
