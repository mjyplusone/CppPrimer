#include <stdio.h>
#include <stdlib.h>

int main()
{
    int m,n,i,j,max;
    int matric[101][101],sum[101]={0},loc[101]={0};
    while(scanf("%d %d",&m,&n)!=EOF)
    {
       for(i=0;i<m;i++)
       for(j=0;j<n;j++)
         scanf("%d",&matric[i][j]);
       for(i=0;i<m;i++)
       {
          max=matric[i][0];
          sum[i]=0;
          for(j=0;j<n;j++)
          {
             sum[i]+=matric[i][j];
             if(matric[i][j]>max)
             {
                max=matric[i][j];
                loc[i]=j;
             }
          }
       }

       for(i=0;i<m;i++)
       {
          for(j=0;j<n;j++)
          {
             if(j==0)
             {
                if(j==loc[i])
                  printf("%d",sum[i]);
                else
                  printf("%d",matric[i][j]);
             }
             else
             {
                if(j==loc[i])
                  printf(" %d",sum[i]);
                else
                  printf(" %d",matric[i][j]);
             }
          }
          printf("\n");
       }

    }

    return 0;
}
