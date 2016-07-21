#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp,*fp2;
    char ch;
    /*
    fp=fopen("C:\\Users\\admin\\Desktop\\aaa.txt","w");
    if(!fp) return 0;
    while((ch=getchar())!=EOF)
      fputc(ch,fp);
    fclose(fp);
    */

    /*
    int flag=0;
    fp=fopen("C:\\Users\\admin\\Desktop\\aaa.txt","r");
    fp2=fopen("C:\\Users\\admin\\Desktop\\bbb.txt","w");
    if(!fp||!fp2) return 0;
    while((ch=fgetc(fp))!=EOF)
    {
       if(ch!=' ')
       {
          fputc(ch,fp2);
          flag=0;
       }
       else if(ch==' '&&flag==0)
       {
          fputc(ch,fp2);
          flag=1;
       }
    }
    fclose(fp); fclose(fp2);
    */

    int numC=0,numW=0,numS=0;
    fp2=fopen("C:\\Users\\admin\\Desktop\\bbb.txt","r");
    if(!fp2) return 0;
    while((ch=fgetc(fp2))!=EOF)
    {
       if(ch!=' ' && ch!='\n') numC++;
       if(ch==' ' || ch=='\n') numW++;
       if(ch=='\n') numS++;
    }
    if(numC!=0) {numW++; numS++;}
    fclose(fp2);
    printf("%d %d %d\n",numC,numW,numS);



    return 0;
}
