#include <bits/stdc++.h>
using namespace std;
int vis[20001],pre[20001],num[20001];
vector<int>g[20001];
int cnt=0,n,e;
void dfs(int x) {
	for (int i=0; i<g[x].size(); i++) {
		int v=g[x][i];
		if (!vis[v]) {
			vis[v]=1;
			pre[++cnt]=v;
			dfs(v);
		}
	}
}
int main() {
	int u,v;
	cin>>n>>e;
	for (int i=1; i<=e; i++) {
		cin>>u>>v;
		g[u].push_back(v);
	}
	for (int i=0; i<n; i++) {
		memset(num,0,sizeof num);
		int len=g[i].size();
		int cn=0;
		for (int j=0; j<len; j++) {
			num[cn++]=g[i][j];
		}
		sort(num,num+len);
		for (int j=0; j<len; j++)
			g[i][j]=num[j];
	}
	for (int i=0; i<n; i++)
		if (!vis[i]) {
			vis[i]=1;
			pre[++cnt]=i;
			dfs(i);
		}
	for (int i=1; i<=cnt; i++)
		cout<<pre[i]<<" ";
	return 0;
}
