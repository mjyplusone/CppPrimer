//假设有A，B，C，D，E五个高等院校进行田径对抗赛，各院校的单项成绩均已存入计算机，并构成一张表，表中每一行的形式为
//项目名称	性别	校名	成绩	得分
//编写算法，处理上述表格，以统计各院校的男、女总分和团体总分，并输出。

#include <stdio.h>
#include <stdlib.h>

typedef enum {A,B,C,D,E}schoolname;
typedef enum {boy,girl}sexname;

typedef struct table
{
   char project;
   sexname sex;
   schoolname school;
   int score;
}tab;

typedef struct count
{
   int boyscore;
   int girlscore;
   int allscore;
}sum;

sum sumscore(schoolname name,tab data[],int n)
{
   sum result;
   result.allscore=0;  result.boyscore=0;  result.girlscore=0;
   int i;
   for(i=0;i<n;i++)
   {
      if(data[i].project==name)
      {
         if(data[i].sex==boy) result.boyscore+=data[i].score;
         else if(data[i].sex==girl) result.girlscore+=data[i].score;
         result.allscore+=data[i].score;
      }
   }
   return result;
}

int main()
{
    return 0;
}
