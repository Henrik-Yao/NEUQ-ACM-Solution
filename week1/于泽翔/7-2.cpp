#include <bits/stdc++.h>
#define N 1000050
using namespace std;
int a[N];
int pre[N], sur[N];
bool v1[N], v2[N];

int main()
{
    int n;
    cin>>n;
    
    for(int i=1; i<=n; i++)
        cin>>a[i];

    for(int i=1; i<=n; i++)
    {
        if(!v1[a[i]])
        {
            pre[i]=pre[i-1]+1;
            v1[a[i]]=true;
        }   
        else
            pre[i]=pre[i-1];
    }
    for(int i=n; i>=1; i--)
    {
        if(!v2[a[i]])
        {
            sur[i]=sur[i+1]+1;
            v2[a[i]]=true;
        }
        else
            sur[i]=sur[i+1];
    }
    int ans=-1;
    for(int i=1; i<n; i++)
        ans=max(ans,pre[i]+sur[i+1]);

    cout<<ans;

    return 0;
}
