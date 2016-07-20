#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N,i,j,temp1,temp2;
    int data[210];
    while(scanf("%d",&N)!=EOF)
    {
       for(i=0;i<N*2;i=i+2)
         scanf("%d %d",&data[i],&data[i+1]);
       for(i=1;i<N*2;i=i+2)
       for(j=i+2;j<N*2;j=j+2)
       {
          if(data[i]>data[j])
          {
             temp1=data[i];
             temp2=data[i-1];
             data[i]=data[j];
             data[i-1]=data[j-1];
             data[j]=temp1;
             data[j-1]=temp2;
          }
          else if(data[i]==data[j] && data[i-1]>data[j-1])
          {
             temp1=data[i];
             temp2=data[i-1];
             data[i]=data[j];
             data[i-1]=data[j-1];
             data[j]=temp1;
             data[j-1]=temp2;
          }
       }
       for(i=0;i<N*2;i=i+2)
       {
          printf("%d %d\n",data[i],data[i+1]);
       }
    }

    return 0;
}
