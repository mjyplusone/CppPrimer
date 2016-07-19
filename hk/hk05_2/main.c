#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
   int pos;
   int value;
}Node;

int main()
{
    int N,i,j,k=0,p,q;
    int matric[4][5],result[2][5];
    Node a[4],temp;
    while(scanf("%d",&N)!=EOF)
    {
       for(i=0;i<4;i++)
       for(j=0;j<5;j++)
         scanf("%d",&matric[i][j]);

       for(j=0;j<5;j++)
       {
          for(i=0;i<4;i++)
          {
             a[k].value=matric[i][j];
             a[k].pos=i;
             k++;
          }
          for(p=0;p<4;p++)
          for(q=p+1;q<4;q++)
          if(a[p].value<a[q].value)
          {
             temp=a[p];
             a[p]=a[q];
             a[q]=temp;
          }
          if(a[0].pos<a[1].pos)
          {
             result[0][j]=a[0].value;
             result[1][j]=a[1].value;
          }
          else
          {
             result[0][j]=a[1].value;
             result[1][j]=a[0].value;
          }
          k=0;
       }

       for(i=0;i<2;i++)
       {
          for(j=0;j<5;j++)
            printf("%d ",result[i][j]);
          printf("\n");
       }

    }
    return 0;
}
