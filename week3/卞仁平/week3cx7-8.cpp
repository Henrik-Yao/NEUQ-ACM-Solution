#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,x;
    cin>>n>>x;
    int a[n];
    int i;
    for(i=0;i<n;i++)cin>>a[i];
    int flag=-1;
    for(i=n-1;i>=0;i--)
    {
        if(x<=a[i])
        {
            flag=i;
        }
    }
    if(flag==-1)
    cout<<n+1;
    else cout<<flag+1;
    return 0;

}