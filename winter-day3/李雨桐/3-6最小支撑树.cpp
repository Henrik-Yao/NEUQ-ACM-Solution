#include <bits/stdc++.h>
using namespace std;

typedef struct
{
    int u;
    int v;
    int w;
} Edge;

int f[205];

bool cmp(Edge e1, Edge e2)
{
    return e1.w<e2.w;
}

void init()
{
    for (int i=0;i<=200;i++)
        f[i] = i;
}

int searc(int x)
{
    if (x==f[x])
        return x;
    return f[x] = searc(f[x]);
}

int mergeflag(int x, int y)
{
    int a=searc(x);
    int b=searc(y);
    if (a!=b)
{
        f[b] = a;
        return 1;
    }
    return 0;
}

int main()
{
    int n,e;

    while (cin>>n>>e)
        {
        Edge edge[e];

        for (int i=0;i<=200;i++)
            f[i] = i;

        for (int i=0;i<e;i++)
        {
            cin>>edge[i].u>>edge[i].v>>edge[i].w;
        }

        sort(edge,edge+e,cmp);

        int num=0,sum=0;
        for (int i=0;i<e;i++)
        {
            if (mergeflag(edge[i].u,edge[i].v))
            {
                num++;
                sum+=edge[i].w;
            }
            if (num==n-1)
                break;
        }
        if (num==n-1)
            cout<<sum<<endl;
        else
            cout<<"There is no minimum spanning tree."<<endl;
    }

    return 0;
}
