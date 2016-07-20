#include <stdio.h>
#include <stdlib.h>

int main()
{
    char a[1001],b[1001];
    int alen,blen,i,j,alllen,temp;
    while(scanf("%s %s",&a,&b)!=EOF)
    {
       int c[1001]={0},d[1001]={0},result[2010]={0};
       alen=strlen(a);
       blen=strlen(b);
       alllen=0;
       for(i=0;i<alen;i++)
         c[alen-1-i]=a[i]-'0';
       for(j=0;j<blen;j++)
         d[blen-1-j]=b[j]-'0';
       if(alen<=blen)
       {
          for(i=0;i<alen;i++)
          {
             result[i]+=c[i]+d[i];
             if(result[i]>9)
             {
                result[i]-=10;
                result[i+1]=1;
             }
          }
          for(i=alen;i<blen;i++)
          {
             result[i]+=d[i];
             if(result[i]>9)
             {
                result[i]-=10;
                result[i+1]=1;
             }
          }
          if(result[i]!=0) alllen=blen+1;
          else alllen=blen;
       }
       else if(alen>blen)
       {
          for(i=0;i<blen;i++)
          {
             result[i]+=c[i]+d[i];
             if(result[i]>9)
             {
                result[i]-=10;
                result[i+1]=1;
             }
          }
          for(i=blen;i<alen;i++)
          {
             result[i]+=c[i];
             if(result[i]>9)
             {
                result[i]-=10;
                result[i+1]=1;
             }
          }
          if(result[i]!=0) alllen=alen+1;
          else alllen=alen;
       }

       for(i=0;i<=alllen/2-1;i++)
       {
          temp=result[i];
          result[i]=result[alllen-1-i];
          result[alllen-1-i]=temp;
       }
       for(i=0;i<alllen;i++)
         printf("%d",result[i]);
       printf("\n");
    }

    return 0;
}
