#include <bits/stdc++.h>
using namespace std;
inline int read()
{
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){ if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){ x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    return x*f;
}
const int N = 50005;
int mp[N],vis[N];
int n;
int dfs(int now)
{
    vis[now] = true;
    if(mp[now]==0) return true;
    if(now+mp[now]<n && now+mp[now]>=0)
    {
        if(!vis[now+mp[now]])
            if(dfs(now+mp[now]))
                return true;
    }
    if(now-mp[now]>=0 && now-mp[now]<n)
    {
        if(!vis[now-mp[now]])
            if(dfs(now-mp[now]))
                return true;
    }
    return false;
}
int main()
{
    // freopen("read.in","r",stdin);
    n = read();
    for(int i=0;i<n;i++)
        mp[i] = read();
    int start = read();
    if(dfs(start))
        cout<<"True";
    else
        cout<<"False";
}