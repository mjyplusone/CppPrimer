#include <stdio.h>
#include <stdlib.h>

int main()
{
    char a[100];
    int len,i,j,flag=0,chong=0;
    while(gets(a))
    {
       len=strlen(a);
       for(i=0;i<len;i++)
       {
          if(a[i]==' ') continue;
          for(j=i+1;j<len;j++)
          {
             if(a[i]==a[j])
             {
                chong=1;
                if(flag==0)
                {
                   printf("%c:%d",a[i],i);
                   flag=1;
                }
                printf(",%c:%d",a[j],j);
                a[j]=' ';
             }
          }
          if(chong==1) {printf("\n"); chong=0;}
          flag=0;
       }
    }

    return 0;
}
