//3.25
#include <stdio.h>
#include <stdlib.h>

int F(int n)
{
   if(n==0) return n+1;
   else if(n>0) return (n*F(n*1.0/2));
}

int main()
{
   int n;  int result;
   scanf("%d",&n);
   result=F(n);
   printf("%d",result);
   return 0;
}
