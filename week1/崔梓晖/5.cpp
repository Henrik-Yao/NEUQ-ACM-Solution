#include <bits/stdc++.h>
using namespace std;
struct people 
{
    int head;
    string name;
}a[100005];
int n,m,x,y,ans=0;
int main()
{
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>a[i].head>>a[i].name;
    }
    for(int i=1;i<=m;i++)
    {
        cin>>x>>y;
        if(a[ans].head==0&&x==0)ans=(ans+n-y)%n;
        else if(a[ans].head==0&&x==1)ans=(ans+y)%n;
        else if(a[ans].head==1&&x==0)ans=(ans+y)%n;
        else if(a[ans].head==1&&x==1)ans=(ans+n-y)%n;
    }
    cout<<a[ans].name;
    return 0;
}
