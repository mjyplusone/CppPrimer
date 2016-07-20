#include <stdio.h>
#include <stdlib.h>

int main()
{
    char str[101];
    int i,j,k,count;
    int num[8];
    while(scanf("%s",&str)!=EOF)
    {
       for(i=0;str[i]!='\0';i++)
       {
          j=0;count=0;
          while(str[i])
          {
             num[j]=str[i]%2;
             if(num[j]==1) count++;
             str[i]=str[i]/2;
             j++;
          }
          for(k=j;k<7;k++)
            num[k]=0;
          if(count%2==0) num[7]=1;
          else num[7]=0;
          for(k=7;k>=0;k--)
            printf("%d",num[k]);
          printf("\n");
       }
    }

    return 0;
}
