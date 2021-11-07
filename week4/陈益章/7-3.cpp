#include <iostream>
#include<cstring>
using namespace std;
int a[10000001];
bool is[10000001];
int sum;
void f(int n)
{
   memset(is,1,sizeof(is));
   is[0]=0;is[1]=0;
    for(int i=2;i<=n;i++)
  {
        if(is[i])
        a[sum++]=i;
        for(int j=0;j<sum&&i*a[j]<=n;j++)
       {
            is[i*a[j]]=0;
            if(i%a[j]==0)
         break;
        }
    }
}
int main()
{
    int n;
    cin>>n;
    f(n);
    cout<<sum<<endl;
}
