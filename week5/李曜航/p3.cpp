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
int n, e;
const int N = 20010;
vector <int> G[N];
bool vis[N];
void dfs(int x)
{
    printf("%d ",x);
    vis[x] = true;
    priority_queue <int> q;
    for(int i=0;i<G[x].size();i++)
    {
        int tp = G[x][i];
        q.push(-tp);
    }
    while(!q.empty())
    {
        int top = -q.top();
        q.pop();
        if(!vis[top])
        {
            dfs(top);
        }
    }
}
int main()
{
    // freopen("read.in","r",stdin);
    n = read(), e = read();
    for(int i=1;i<=e;i++)
    {
        int a = read(), b = read();
        // if(a>b) swap(a,b);
        // G[b].push_back(a);
        G[a].push_back(b);
    }

    for(int i=0;i<n;i++)
    {
        if(vis[i]==0)
            dfs(i);
    }
    return 0;
}