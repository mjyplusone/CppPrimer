#include <iostream>

using namespace std;

void sort(int *a,int N)
{
   int temp,i,j;
   for(i=0;i<N;i++)
   for(j=i+1;j<N;j++)
   {
      if(a[i]>a[j])
      {
         temp=a[i];
         a[i]=a[j];
         a[j]=temp;
      }
   }
}

int main()
{
    int *a,N,i;
    while(cin>>N)
    {
       a=new int[N];
       for(i=0;i<N;i++)
         cin>>a[i];
       if(N==1) {cout<<a[0]<<endl; cout<<-1<<endl;}
       else
       {
          sort(a,N);
          cout<<a[N-1]<<endl;
          for(i=0;i<N-1;i++)
            cout<<a[i]<<" ";
          cout<<endl;
       }
    }
    return 0;
}
