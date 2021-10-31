#include<bits/stdc++.h>
using namespace std;
const int maxn = 510;
vector<int>G[maxn];
int s, t;
int f[maxn];
int dfs(int u){
	if(f[u])return f[u];
	if(u==t)return 1;
	for(int i = 0; i < G[u].size(); i++){
		int v = G[u][i];
		f[u] += dfs(v);
	}
	return f[u];
}
int ok=1;
int vis[510];
void bfs(){
	queue<int>q;
	q.push(s);
	while(q.size()){
		int tmp = q.front();  q.pop();
		if(vis[tmp])continue;
		vis[tmp] = 1;
		if(f[tmp]==0){
			ok = 0; break;
		}
		if(tmp==t)continue;
		for(int i = 0; i < G[tmp].size(); i++){
			int v = G[tmp][i];
			q.push(v);
		}
	}
}
int main(){
	int n, m;
	cin>>n>>m;
	for(int i = 1; i <= m; i++){
		int u, v;  cin>>u>>v;
		G[u].push_back(v);
	}
	cin>>s>>t;
	dfs(s);
	cout<<f[s]-f[t]<<" ";
	f[t] = 1;
	bfs();
	if(ok)cout<<"Yes\n";
	else cout<<"No\n";
	return 0;
}
