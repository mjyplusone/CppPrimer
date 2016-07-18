#include <stdio.h>
#include <stdlib.h>

int main()
{
    int year,data,mon,day;
    int month[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    int i,sum=0;

    while(scanf("%d %d",&year,&data)!=EOF)
    {
       if((year%100!=0 && year%4==0) || (year%400==0))
       {
          month[1]=29;
       }
       for(i=0;i<12;i++)
       {
          sum+=month[i];
          if(sum>=data) break;
       }
       mon=i+1;
       day=data-(sum-month[mon-1]);
       printf("%04d-%02d-%02d\n",year,mon,day);
       sum=0; month[1]=28;  // !!!
    }
    return 0;
}
