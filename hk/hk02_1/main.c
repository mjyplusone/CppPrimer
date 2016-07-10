//Í³¼Æµ¥´Ê
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char string[10000];
    int i,count[1000]={0},num=0;
    while(gets(string)!=NULL)
    {
       for(i=0;string[i];i++)
       {
          count[num]++;
          if(string[i]==' ' || string[i]=='.')
          {
             count[num]--;
             num++;
          }
       }
       for(i=0;i<num-1;i++)
         printf("%d ",count[i]);
       printf("%d\n",count[i]);
    }

    return 0;
}
