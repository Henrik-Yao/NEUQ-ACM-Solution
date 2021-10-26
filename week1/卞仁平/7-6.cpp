
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,tt;
    cin>>n>>tt;
    int i;
    int a[n],t[n];
    for(i=0;i<n;i++)cin>>a[i]>>t[i];
    int s[n];
    for(i=0;i<n;i++)
    {
        if(t[i]>tt)s[i]=a[i]-t[i]+tt;
        else s[i]=a[i];
    }
    sort(s,s+n);
    cout<<s[n-1];
    
}