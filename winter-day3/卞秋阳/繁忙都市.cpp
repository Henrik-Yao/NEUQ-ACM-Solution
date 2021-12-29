#include<bits/stdc++.h>
using namespace std;
struct node{
	int from;
	int to;
	int cost;
};
bool cmp(node a,node b); 
node s[20000];
int p[20000];
int n,m,ans;
int find(int x){
	if(p[x]==x) return x;
	else return find(p[x]);
}
int main()
{
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
	 p[i]=i;
	}
	for(int i=0;i<m;i++)
	{
		cin>>s[i].from>>s[i].to>>s[i].cost;
	}
	sort(s,s+m,cmp);
	int cou=0;
	for(int i=0;i<m;i++)
	{
		int fx=find(s[i].from);
		int fy=find(s[i].to);
		if(fx!=fy)
		{
			p[fy]=fx;
			ans=max(ans,s[i].cost);
		}
	}
	cout<<n-1<<" "<<ans;
}
bool cmp(node a,node b)
{
	return a.cost<b.cost;
}
