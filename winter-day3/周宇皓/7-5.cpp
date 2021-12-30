#include<bits/stdc++.h>
using namespace std;
const int N=1509;
struct Edge
{
    int a,b,dis;
}edge[N*2];
int n,m,bin[N];
bool cmp(const Edge&a,const Edge&b)
{
    return a.dis<b.dis;
}
int find(int x)
{
    if(x!=bin[x]) bin[x]=find(bin[x]);
    return bin[x];
}
int main()
{
    while(cin>>n>>m)
    {
    for(int i=0;i<m;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        edge[i]={a,b,c};
    }
    for(int i=1;i<=n;i++) bin[i]=i;
    sort(edge,edge+m,cmp);
    int cnt=0,sum=0;
    for(int i=0;i<m;i++)
    {
        int fa=find(edge[i].a),fb=find(edge[i].b);
        if(fa!=fb)
        {
            bin[fa]=fb,cnt++;
            sum+=edge[i].dis;
        }
        if(cnt==n-1) break;
    }
    if(cnt==n-1) cout<<sum<<endl;
    else printf("There is no minimum spanning tree.\n");
    }
    return 0;
}
