#include <bits/stdc++.h>
using namespace std;
int n;
vector <int> g[10001];
int in[10001];
int temp[10001];
void solve() {
	int t,x;
	cin>>t;
	for (int i=1; i<=t; i++) {
		cin>>x;
		temp[x]=0;
		for (int j=0; j<g[x].size(); j++) {
			int v=g[x][j];
			temp[v]--;
		}
	}
	for (int i=1; i<=n; i++)
		if (temp[i]>0) {
			cout<<"NO"<<endl;
			return;
		}
	cout<<"YES"<<endl;
	return;
}

int main() {
	int m,u,v;
	cin>>n>>m;
	for (int i=1; i<=m; i++) {
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
		in[u]++;
		in[v]++;
	}
	int k;
	cin>>k;
	while(k--) {
		for (int i=1; i<=n; i++)
			temp[i]=in[i];
		solve();
	}
	return 0;
}
