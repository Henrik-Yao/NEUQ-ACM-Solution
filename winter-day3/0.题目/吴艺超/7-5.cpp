#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct ax
{
	int x,y,z;
}edg[500010];
int fa[100010],n,m,tot,maxx;
bool operator <(ax a, ax b)
{
	return a.z<b.z;
}
int get(int x)
{
	if(x==fa[x]) return x;
	return fa[x]=get(fa[x]);
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	cin>>edg[i].x>>edg[i].y>>edg[i].z;
	sort(edg+1,edg+m+1);
	for(int i=1;i<=n;i++)
	fa[i]=i;
	for(int i=1;i<=m;i++){
		int x=get(edg[i].x);
		int y=get(edg[i].y);
		if(x==y)continue;
		fa[x]=y;
		maxx=max(edg[i].z,maxx);
	}
	cout<<n-1<<" "<<maxx;
}
