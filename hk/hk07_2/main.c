#include <stdio.h>
#include <stdlib.h>

int main()
{
    char str[1001];
    int len,i,flag=0;
    while(scanf("%s",&str)!=EOF)
    {
       len=strlen(str);
       for(i=0;i<len/2-1;i++)
       {
          if(str[i]!=str[len-1-i])
          {
             flag=1;
             break;
          }
       }
       if(flag==0) printf("Yes!\n");
       else printf("No!\n");
       flag=0;
    }

    return 0;
}
