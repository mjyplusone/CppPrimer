//采用命令行方式复制任意多个文件内容到一个文件中
//命令行形式：mycopy 1.txt 2.txt 3.txt 4.txt...
//功能：复制2、3、4内容到1中
#include <stdio.h>
#include <stdlib.h>
#define BUFFERSIZE 1000

int main(int argc,char *argv[])
{
    if(argc<3) {printf("参数不足!\n"); return 0;}
    int i;
    FILE *fp;
    if((fp=fopen(argv[1],"a"))==NULL)
    {
       printf("Error open!\n");
       return 0;
    }
    FILE *fpSRC;
    for(i=2;i<argc;i++)
    {
       if((fpSRC=fopen(argv[i],"r"))==NULL)
       {
          printf("Open Error!\n");
          return 0;
       }
       char temp[BUFFERSIZE+1];
       while(fgets(temp,BUFFERSIZE,fpSRC))
       {
          fprintf(fp,"%s\n",temp);
       }
       fclose(fpSRC);
    }
    printf("Copy success!\n");
    fclose(fp);
    return 0;

    return 0;
}
