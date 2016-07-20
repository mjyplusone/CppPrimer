#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N,i,j;
    int num[6]={0};
    while(scanf("%d",&N)!=EOF)
    {
       i=0;
       if(N==0) printf("0\n");
       else
       {
          while(N)
          {
             num[i]=N%8;
             N=N/8;
             i++;
          }
          for(j=i-1;j>=0;j--)
          {
             printf("%d",num[j]);
             num[j]=0;
          }
          printf("\n");
       }
    }

    return 0;
}
