#include<bits/stdc++.h>
using namespace std;
struct road{
    int from;
	int to;
	int cost;
}r[50001];
int pre[301];
int find(int x)
{
    if(x==pre[x])
	{
		return x;
	}
    return pre[x]=find(pre[x]);
}
void Union(int u,int v)
{
    int x=find(u),y=find(v);
    if(x==y)
	{
		return;
	}
    pre[x]=y;
}
bool compair(road u,road v)
{
    return u.cost<v.cost;
}
int main()
{
    int n,m,count=0,max=0;
	cin>>n>>m;
	for(int i=0;i<n;i++)
    {
    	pre[i]=i;
	}
    for(int i=0;i<m;i++)
    {
        cin>>r[i].from>>r[i].to>>r[i].cost;
    }
    sort(r,r+m,compair);
    for(int i=0;i<m;i++)
    {
        if(find(r[i].from)!=find(r[i].to))
        {
            Union(r[i].from,r[i].to);
            if(r[i].cost>max)
            {
            	max=r[i].cost;
			}
            count++;
        }
    }
    cout<<count<<" "<<max;
    return 0;
}
