#include <bits/stdc++.h>
using namespace std;
vector<int>vax[510];
int n, m, w[510], bg, ed, f=1, x, y;

int dfs(int x)
{
	int res=0;
	
	if(w[x]!=-1)
		return w[x];
	for(int i=0; i<vax[x].size(); i++)
	{
		if(w[vax[x][i]]==-1)
			dfs(vax[x][i]);
		res+=w[vax[x][i]];
	}
	if(res==0)
		f=0;
	w[x]=res;
	
	return res;
}
int main(void)
{
	cin>>n>>m;
	memset(w, -1, sizeof(w));
	for(int i=1; i<=m; i++)
	{
		cin>>x>>y;
		vax[x].push_back(y);
	}
	cin>>bg>>ed;
	w[ed]=1;
	
	cout<<dfs(bg)<<' ';
	if(f)
		cout<<"Yes";
	else
		cout<<"No";
	
	return 0;
}