#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N,i,j,flag=0;
    int a[4];
    while(scanf("%d",&N)!=EOF && (N>=1&&N<=500))
    {
       for(i=0;i<N;i++)
       {
          scanf("%d.%d.%d.%d",&a[0],&a[1],&a[2],&a[3]);
          for(j=0;j<4;j++)
          {
             if(a[j]<0 || a[j]>255)
             {
                flag=1;
                break;
             }
          }
          if(flag==0) printf("Yes!\n");
          else printf("No!\n");
          flag=0;
       }
    }

    return 0;
}
