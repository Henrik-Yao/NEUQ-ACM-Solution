#include<bits/stdc++.h>
using namespace std;
int m[1001][1001],n;
int dis[1001],f[1001],Distance=0;
bool visit[1001];

void find_way(int from)
{
    dis[from]=0;
    for(int i=0;i<n;i++)
        f[i]=i;
    for(int i=0;i<n;i++)
    {
        int mmin=99999999,p=-1;
        for(int j=0;j<n;j++)
        {
            if(visit[j]==0 && dis[j]<mmin)
            {
                mmin=dis[j];
                p=j;
            }
        }
        if(p==-1) return ;
        visit[p]=1;
        for(int k=0;k<n;k++)
        {
            if(visit[k]==0 && m[p][k]<dis[1000] && dis[p]+m[p][k]<dis[k])
            {
                dis[k]=dis[p]+m[p][k];
                f[k]=p;
            }
        }
    }
}

void print_way(int from,int to)
{
    if(from==to)
    {
        cout<<from;
        return ;
    }
    Distance=Distance+m[to][f[to]];
    print_way(from,f[to]);
    cout<<"-->"<<to;
}

int main()
{
    int e,a,b,c;
    memset(m,0x3f,sizeof(m));
    memset(dis,0x3f,sizeof(dis));
    memset(visit,0,sizeof(visit));
    cin>>n>>e;
    for(int i=0;i<e/2;i++)
    {
        cin>>a>>b>>c;
        m[a][b]=c;
        m[b][a]=c;
    }
    int from,to;
    cin>>from>>to;
    if(from==to)
    {
        cout<<from<<"-->"<<to<<":0";
        return 0;
    }
    find_way(from);
    print_way(from,to);
    cout<<":"<<Distance;
    return 0;
}