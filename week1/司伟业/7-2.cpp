#include<iostream>
#include<cstdio>
using namespace std;
int n,a[1000005],ans,aa[100002],bb[100002];
int ans1[1000005],ans2[1000005];
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(!aa[a[i]])
        {
            aa[a[i]]=1;
            ans1[i]=ans1[i-1]+1;
        }
        else ans1[i]=ans1[i-1];
    }
    for(int i=n;i>=1;i--)
    {
        if(!bb[a[i]])
        {
            bb[a[i]]=1;
            ans2[i]=ans2[i+1]+1;
        }
        else ans2[i]=ans2[i+1];
    }
    for(int i=1;i<n;i++)
    {
        ans=max(ans,ans1[i]+ans2[i+1]);  
    }
    cout<<ans;
    return 0;
}
