#include <stdio.h>
#include <stdlib.h>
#define size 100

int main()
{
    int matric[size][size];
    int n,i,j;
    int flag=1;
    while(scanf("%d",&n)!=EOF)
    {
       for(i=0;i<n;i++)
       for(j=0;j<n;j++)
         scanf("%d",&matric[i][j]);
       for(i=1;i<n;i++)
       for(j=0;j<i;j++)
       if(matric[i][j]!=matric[j][i])
       {
          flag=0;
          break;
       }
       if(flag) printf("Yes!\n");
       else     printf("No!\n");
       flag=1;
    }
    return 0;
}
