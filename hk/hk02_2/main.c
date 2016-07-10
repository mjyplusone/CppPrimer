//สุะฮสý
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N,square,num;
    while(scanf("%d",&N)!=EOF)
    {
       square=N*N;
       if(N>2 && N<10)
       {
          num=square%10;
       }
       else if(N>=10 && N<100)
       {
          num=square%100;
       }
       else
         printf("Input Error!\n");
       if(num==N) printf("Yes!\n");
       else       printf("No!\n");
       num=0; square=0;
    }
    return 0;
}
