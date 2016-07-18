#include <stdio.h>
#include <stdlib.h>
#define maxsize 30

typedef struct staff
{
   int num;
   char name[10];
   int year;
}staff;

int main()
{
    int N,i,j;
    staff inf[maxsize],temp;
    while(scanf("%d",&N)!=EOF)
    {
       for(i=0;i<N;i++)
       {
          scanf("%d %s %d",&inf[i].num,&inf[i].name,&inf[i].year);
       }

       for(i=0;i<N;i++)
       for(j=i+1;j<N;j++)
       {
          if(inf[i].year>inf[j].year)
          {
             temp=*(inf+i);
             *(inf+i)=*(inf+j);
             *(inf+j)=temp;
          }
          else if(inf[i].num>inf[j].num && inf[i].year==inf[j].year)
          {
             temp=*(inf+i);
             *(inf+i)=*(inf+j);
             *(inf+j)=temp;
          }
          else if(inf[i].name>inf[j].num && inf[i].num==inf[j].num && inf[i].year==inf[j].year)
          {
             temp=*(inf+i);
             *(inf+i)=*(inf+j);
             *(inf+j)=temp;
          }
       }

       if(N<3)
       {
          for(i=0;i<N;i++)
            printf("%d %s %d\n",inf[i].num,inf[i].name,inf[i].year);
       }
       else
       {
          for(i=0;i<3;i++)
            printf("%d %s %d\n",inf[i].num,inf[i].name,inf[i].year);
       }
    }

    return 0;
}
