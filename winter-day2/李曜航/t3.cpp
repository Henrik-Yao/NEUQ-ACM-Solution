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
const int N = 1005;
int dep[N];
int fa[N][50];
int lg[N];
vector<int> G[N];

void buildLCA(int now, int fath)
{
    fa[now][0] = fath;
    dep[now] = dep[fath] + 1;
    for(int i=1;i<=lg[dep[now]];i++)
        fa[now][i] = fa[fa[now][i-1]][i-1];
    for(int i=0;i<G[now].size();i++)
    {
        int v = G[now][i];
        if(v!=fath) buildLCA(v,now);
    }
}
int getLCA(int x, int y)
{
    if(dep[x]<dep[y]) swap(x,y);

    while(dep[x]>dep[y])
        x = fa[x][lg[dep[x]-dep[y]]-1];//? 

    if(x==y) return x; 

    for(int i=lg[dep[x]]-1;i>=0;i--)
    {
        if(fa[x][i]!=fa[y][i])
            x = fa[x][i], y = fa[y][i];
    }
    return fa[x][0];
}
// bool visi[N];
// void dfs(int x)
// {
//     visi[x] = true;
//     printf("%d ",x);
//     for(int i=0;i<G[x].size();i++)
//     {
//         if(!visi[G[x][i]])
//             dfs(G[x][i]);
//     }
// }
int main()
{
    freopen("read.in","r",stdin);
    for(int i = 1; i <= 1000; i++)
        lg[i] = lg[i-1] + (1 << lg[i-1] == i);
    int groups = read();
    while(groups--)
    {
        int a;
        int root = read();
        stack<int> s;
        memset(fa,0,sizeof(fa));
        memset(dep,0,sizeof(dep));
        for(int i=0;i<N;i++)
            G[i].clear();

        s.push(root);
        while(!s.empty())
        {
            a = read();
            if(a==0) s.pop();
            else
            {
                // node[cnt] = make_pair(cnt,read());
                G[s.top()].push_back(a);
                G[a].push_back(s.top());
                s.push(a);
            }
        }
        a = read();
        // if(a==0) 
        //     printf("ko\n");
        // dfs(root);
        buildLCA(root,0);
        int q1 = read(), q2 = read();
        cout<<getLCA(q1,q2)<<endl;
    }
}