#include <bits/stdc++.h>
using namespace std;
struct tu
{
	int from;
	int to;
	int dis;
	friend bool operator < (tu &a,tu &b) {return (a.dis<b.dis);}
}Map[100050];
int n,m;
int ans,cnt=0;
int pre[305];
int rak[305];
int findroot(int x)
{
	while(pre[x]!=x) x=pre[x];
	return x;
}
int union_(int x,int y)
{
	int x_root = findroot(x);
	int y_root = findroot(y);
	if(x_root==y_root) return 0;
	else ;
	if(rak[x_root]<rak[y_root] ) pre[x_root]=y_root;
	else if(rak[y_root]<rak[x_root]) pre[y_root] = x_root;
	else 
	{
		pre[x_root] = y_root;
		rak[y_root]++;
	}
	return 1;
}
int main()
{
	cin>>n>>m;
	for(int i=0;i<m;i++) cin>>Map[i].from>>Map[i].to>>Map[i].dis;
	sort(Map,Map+m);
	for(int i=0;i<=n;i++) pre[i]=i;
    memset(rak,0,sizeof(rak));
	for(int i=0;i<m;i++)
	{
		if(union_(Map[i].from,Map[i].to))
		{
			cnt++;
			ans = Map[i].dis;
			if(cnt==n-1) break;
		}
	}
	cout<<cnt<<' '<<ans;
	return 0;
} 




