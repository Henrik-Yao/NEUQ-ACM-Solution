#include<iostream>
using namespace std;
int a[1000001];
int main()
{
    int n,x,flag=0;
    cin>>n>>x;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++)
    {
        if(a[i]>=x)
        {
            cout<<i;
            flag=1;
            break;
        }
    }
    if(flag==0) cout<<n+1;
    return 0;
}