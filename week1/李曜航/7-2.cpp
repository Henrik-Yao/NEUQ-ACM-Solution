#include <bits/stdc++.h>
using namespace std;

const int N = 1e6+20;
int a[N];
int pre[N],sur[N];
bool vis1[N],vis2[N];
inline int read()
{
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){ if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){ x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    return x*f;
}
int main()
{
    // freopen("000A.in","r",stdin);
    int n = read();
    for(int i=1;i<=n;i++)
        a[i] = read();

    for(int i=1;i<=n;i++)
    {
        if(!vis1[a[i]])
        {
            pre[i] = pre[i-1]+1;
            vis1[a[i]] = true;
        }   
        else
            pre[i] = pre[i-1];
    }
    for(int i=n;i>=1;i--)
    {
        if(!vis2[a[i]])
        {
            sur[i] = sur[i+1]+1;
            vis2[a[i]] = true;
        }
        else
            sur[i] = sur[i+1];
    }
    int ans = -1;
    for(int i=1;i<n;i++)
        ans = max(ans,pre[i]+sur[i+1]);

    // for(int i=1;i<=n;i++)
    //     for(int j=n;j>=1;j--)
    //     {
    //         if(i==j){break;}
    //         ans = max(ans,pre[i]+sur[j]);
    //     }

    cout<<ans;

    return 0;
}