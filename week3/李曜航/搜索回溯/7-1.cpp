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
int n, m, k;
int s,to;
const int N = 110;
bool safe[N];
int fa[N];
vector <int> G[N];
int find(int x)
{
    if(fa[x]==x) return x;
    return find(fa[x]);
}
void merge(int a, int b)
{
    fa[find(a)] = find(b);
}
void dfs(int x)
{
    for(int i=0;i<G[x].size();i++)
    {
        if(safe[G[x][i]])
        {
            merge(x,G[x][i]);
            dfs(G[x][i]);
        }
    }
}
int main()
{
    m = read(), n = read(), k = read();
    for(int i=1;i<=n;i++)
    {
        int tmp = read();
        safe[tmp] = true;
    }
    for(int i=1;i<=k;i++)
    {
        int a = read(), b = read();
        G[a].push_back(b);
        G[b].push_back(a);
    }
    s = read(); to = read();
    if(!safe[to])
        {printf("The city %d is not safe!",to);return 0;}

    for(int i=0;i<=m;i++)
        fa[i] = i;
    dfs(s);

    if(find(s)==find(to)){printf("The city %d can arrive safely!",to);return 0;}
    else {printf("The city %d can not arrive safely!",to);return 0;}
    








}