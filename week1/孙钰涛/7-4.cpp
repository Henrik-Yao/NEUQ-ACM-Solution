#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    long long a[1001]={0,1};
    for(int i=2;i<=n;i++)
    {
        a[i]++;
        for(int j=1;j<=i/2;j++)
        {
            if(i%j==0) a[i]=a[i]+a[j];
        }
    }
    cout<<a[n];
    return 0;
}