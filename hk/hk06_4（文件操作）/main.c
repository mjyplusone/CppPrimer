//���������з�ʽ�����������ļ����ݵ�һ���ļ���
//��������ʽ��mycopy 1.txt 2.txt 3.txt 4.txt...
//���ܣ�����2��3��4���ݵ�1��
#include <stdio.h>
#include <stdlib.h>
#define BUFFERSIZE 1000

int main(int argc,char *argv[])
{
    if(argc<3) {printf("��������!\n"); return 0;}
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
