#include <stdio.h>
#include <stdlib.h>

//递归
long long F(int n)
{
   if(n==1) return 1;
   else if(n==2) return 2;
   else return F(n-1)+F(n-2);
}

int main()
{
    int N,i;
    long long result;
    long long a[90];    //注意要用long long类型
    while(scanf("%d",&N)!=EOF)
    {
       //result=F(N);
       //非递归写法
       a[1]=1; a[2]=2;
       for(i=3;i<=N;i++)
         a[i]=a[i-1]+a[i-2];
       printf("%lld\n",a[N]);
       for(i=0;i<N;i++)
         a[i]=0;

       //printf("%lld\n",result);
       //result=0;
    }

    return 0;
}
