#include <stdio.h>
#include <stdlib.h>

int main()
{
    char str1[101],str2[101],result[210];
    int i,j;
    while(scanf("%s %s",&str1,&str2)!=EOF)
    {
       j=0;
       for(i=0;str1[i]!='\0';i++)
       {
          result[j]=str1[i];
          j++;
       }
       for(i=0;str2[i]!='\0';i++)
       {
          result[j]=str2[i];
          j++;
       }
       for(i=0;i<j;i++)
         printf("%c",result[i]);
       printf("\n");
    }

    return 0;
}
