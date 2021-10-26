#include <bits/stdc++.h>
using namespace std;
inline int read()
{
    char ch = getchar();
    int s = 0, w = 1;
    while(ch < '0' || ch > '9')
    {
        if(ch == '-') w = -1;
        ch = getchar();
    }
    while(ch >= '0' && ch <= '9')
    {
        s = s * 10 + ch - '0',
        ch = getchar();
    }
    return s * w;
}
const int N = 10010;
vector <int> G[N];
int beat[N];
int n,m;
bool vis[N];
int finded;
int savecheck[N];



bool dfs(int s)
{
    for(int i=0;i<G[s].size();i++)
    {
        int to = G[s][i];
        if(!vis[to])
            return false;
    }
    return true;
}
// int check(int np)
// {
//     bool flag = true;
//     for(int i=1;i<=np;i++)
//         if(beat[savecheck[i]]!=2) flag = false;
//     if(flag)
//         return true;
//     return false;
// }
int main()
{
//     freopen("read.in","r",stdin);
//     freopen("write.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int a = read(), b = read();
        G[a].push_back(b);
        G[b].push_back(a);
    }
    int k = read();
    while(k--)
    {
        memset(vis,0,sizeof(vis));
        memset(beat,0,sizeof(beat));
        int np = read();

        for(int i=1;i<=np;i++)
        {
            int da = read();
            vis[da] = true;
        }   
        int flag = true;
        for(int i=1;i<=n;i++)
        {
            if(vis[i])
                continue;
            if(!dfs(i)) {flag = false;break;}
        }
        if(flag) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    
    
    return 0;
}