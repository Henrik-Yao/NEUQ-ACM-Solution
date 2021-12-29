#include <bits/stdc++.h>
using namespace std;
typedef struct 
{
    int u;
    int v;
    int w;
}bian;
int a[1505];
bool cmp(bian edge1,bian edge2)
{return edge1.w<edge2.w;}
void chushi()
{
    for(int i=0;i<=200;i++)
    a[i]=i;
}
int find (int x)
{
    int y=x;
    while(a[y]!=y)
    y=a[y];
    return y;
}
int add(int x,int y)
{
    int fx=find(x);
    int fy=find(y);
    if(fx!=fy)
    {
        a[fy]=fx;
        return 1;
    }
    return 0;
}
int main()
{
    int n,e;
    while(cin>>n>>e)
    {
        bian edge[e];
        chushi();
        for(int i=0;i<e;i++)
        cin>>edge[i].u>>edge[i].v>>edge[i].w;
        sort(edge,edge+e,cmp);
        int cnt=0;
        int sum=0;
        for(int i=0;i<e;i++)
        {
            if(add(edge[i].u,edge[i].v))
            {
                cnt++;sum+=edge[i].w;
            }
            if(cnt==n-1)break;
        }
        if(cnt==n-1)
        cout<<sum<<endl;
        else 
        cout<<"There is no minimum spanning tree.\n";
    }
    return 0;
}