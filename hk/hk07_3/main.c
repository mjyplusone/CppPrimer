#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N,i,j;
    int matric[101][101];
    while(scanf("%d",&N)!=EOF && (N>=1 && N<=100))
    {
       for(i=0;i<N;i++)
       for(j=0;j<N;j++)
         scanf("%d",&matric[i][j]);
       for(i=0;i<N;i++)
       for(j=0;j<N;j++)
       {
          if(j==N-1)
            printf("%d\n",matric[j][i]);
          else
            printf("%d ",matric[j][i]);
       }
    }

    return 0;
}
