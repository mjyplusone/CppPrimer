//������A��B��C��D��E����ߵ�ԺУ�����ﾶ�Կ�������ԺУ�ĵ���ɼ����Ѵ���������������һ�ű�����ÿһ�е���ʽΪ
//��Ŀ����	�Ա�	У��	�ɼ�	�÷�
//��д�㷨���������������ͳ�Ƹ�ԺУ���С�Ů�ֺܷ������ܷ֣��������

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
