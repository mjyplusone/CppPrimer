//判定一个C语言变量的命名是否正确
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char str[255],len,i;
    while(scanf("%s",&str)!=EOF)
    {
       if(!(str[0]=='_' || (str[0]>='a'&&str[0]<='z') || (str[0]>='A'&&str[0]<='Z')))
       {
          printf("Wrong!\n");
          continue;
       }

       len=strlen(str);
       for(i=1;i<len;i++)
       {
          if(!(str[i]=='_' || (str[i]>='a'&&str[i]<='z') || (str[i]>='A'&&str[i]<='Z') || (str[i]>='0'&&str[i]<='9')))
          {
             printf("Wrong!\n");
             continue;
          }
       }
       printf("Correct!\n");
    }

    return 0;
}
