#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    int a[100005];
    while(t--)
    {
        int n,m;
        cin>>m;
        int i;
        for(i=0;i<m;i++)cin>>a[i];
        cin>>n;
        for(i=m;i<n+m;i++)cin>>a[i];
        sort(a,a+m+n);
        for(i=0;i<m+n-1;i++)cout<<a[i]<<" ";
        cout<<a[m+n-1]<<endl;
    }
    return 0;
}