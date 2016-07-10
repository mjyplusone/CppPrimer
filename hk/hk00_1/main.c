#include <stdio.h>
#include <stdlib.h>

int main()
{
   unsigned int n,i;
   long long int X=0,Y=0,temp=1;
   while(scanf("%d",&n)!=EOF)
   {
      for(i=1;i<=n;i++)
      {
         temp*=i;
         if(i%2==0) Y+=temp;
         else       X+=temp;
      }
      printf("%lld %lld\n",X,Y);    //long long int  -->  lld
      X=0;Y=0;temp=1;               // !
   }


   return 0;
}
