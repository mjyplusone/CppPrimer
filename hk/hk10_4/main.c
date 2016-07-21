//不用字符库函数，无冗余的接收两个字符串，再无冗余的连接起来
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i=1,j=1,k;
    char ch;
    char *p1=(char*)malloc(sizeof(char));
    char *p2=(char*)malloc(sizeof(char));
    while((ch=getchar())!='\n')
    {
       p1=(char*)realloc(p1,i*sizeof(char));
       *(p1+i-1)=ch;
       i++;
    }
    p1=(char*)realloc(p1,i*sizeof(char));
    *(p1+i-1)='\0';
    while((ch=getchar())!='\n')
    {
       p2=(char*)realloc(p2,j*sizeof(char));
       *(p2+j-1)=ch;
       j++;
    }
    p2=(char*)realloc(p2,j*sizeof(char));
    *(p2+j-1)='\0';

    p1=(char*)realloc(p1,(i+j-1)*sizeof(char));
    for(k=0;k<j;k++)
      *(p1+i-1+k)=*(p2+k);

    printf("%s\n",p1);
    puts(p1);

    return 0;
}
