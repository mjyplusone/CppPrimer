#include <stdio.h>
#include <stdlib.h>

typedef struct Text
{
   char data[1001];
   int len;
}Text;

int main()
{
    Text text[1000];
    int i=0,j,minlen,maxlen;
    while(scanf("%s",&text[i].data)!=EOF)
    {
       text[i].len=strlen(text[i].data);
       if(i==0)
       {
          minlen=maxlen=text[i].len;
       }
       else
       {
          if(text[i].len<minlen)
            minlen=text[i].len;
          if(text[i].len>maxlen)
            maxlen=text[i].len;
       }
       i++;
    }
    for(j=0;j<i;j++)
    {
       if(text[j].len==minlen)
         printf("%s\n",text[j].data);
    }
    for(j=0;j<i;j++)
    {
       if(text[j].len==maxlen)
         printf("%s\n",text[j].data);
    }

    return 0;
}
