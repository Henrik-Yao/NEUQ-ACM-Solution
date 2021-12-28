#include<bits/stdc++.h>
using namespace std;

int read()
{
    int x=0,f=1;char c=getchar();
    while(c<'0'||c>'9'){if(c=='-') f=-1;c=getchar();}
    while(c>='0'&&c<='9') x=(x<<3)+(x<<1)+(c^48),c=getchar();
    return x*f;
}//快读，不理解的同学用cin代替即可
const int inf = 123456789;
const int maxn = 5005;
const int maxm = 200005;
struct edge{
    int to;
    int w;
};
vector<edge> G[maxn];

int n,m,ans,now = 1;
int dis[maxn];
bool vis[maxn];
void prim()
{
    memset(dis,0x3f,sizeof(dis));
    for(int i=0;i<G[1].size();i++)
    {
        int to = G[1][i].to;
        int w = G[1][i].w;
        dis[to] = min(dis[to],w);
    }//更新第一个节点
    int cnt = 0;
    while(++cnt<n)
    {
        int minn = inf;
        vis[now] = true;
        for(int i=1;i<=n;i++)
        {
            if(!vis[i] && minn>dis[i])
            {
                minn = dis[i];
                now = i;
            }
        }
        ans = max(ans,minn);
        //枚举now的所有连边，更新dis数组
        for(int i=0;i<G[now].size();i++)
        {
            int w = G[now][i].w;
            int to = G[now][i].to;
            if(dis[to]>w && !vis[to])
            {
                dis[to] = w;
            }
        }
    }
    return;

}
void init()
{
    n = read(), m = read();
    int w, a, b;
    for(int i=1;i<=m;i++)
    {
        a = read(), b = read(), w = read();
        edge e1,e2;
        e1.to = b; e1.w = w;
        e2.to = a; e2.w = w;
        G[a].push_back(e1);
        G[b].push_back(e2);
    }
}
int main()
{
    init();
    prim();
    cout<<n-1<<" "<<ans;
}