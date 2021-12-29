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
const int N = 20005;
struct Edge{
    int to;
    int w;
};
vector<Edge> G[N];
int cmp(Edge a, Edge b)
{
    return a.to < b.to;
}

int main()
{
    // freopen("read.in","r",stdin);
    int n = read(), m = read();
    for(int i=1;i<=m;i++)
    {
        int f = read(), t = read(), v = read();
        Edge e1; e1.to = t, e1.w = v;
        // Edge e2; e2.to = f, e2.w = v;
        G[f].push_back(e1);
    }
    int k = read();
    for(int i=1;i<=k;i++)
    {
        int a = read(), b = read();
        vector<Edge>::iterator p1;
        for(p1=G[a].begin();p1!=G[a].end();p1++)
        {
            if(b==p1->to)
            {
                G[a].erase(p1);
                break;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        if(G[i].empty()) continue;

        cout<<i<<":";
        sort(G[i].begin(),G[i].end(),cmp);
        for(int j=0;j<G[i].size();j++)
        {
            printf("(%d,%d,%d)",i,G[i][j].to,G[i][j].w);
        }
        cout<<endl;
    }



}