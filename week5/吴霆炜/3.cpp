#include <bits/stdc++.h>
using namespace std;
#define maxn 20000

vector <int> p[maxn];
bool vis[maxn];
void dfs(int v){
	cout<<v<<' ';
	vis[v] = true;
	for(auto i:p[v]){
		if(vis[i])continue;
		dfs(i);
	}
}

int main(){
	int temp;
	int vexnum,arcnum;
	cin>>vexnum>>arcnum;
	for(int i = 0;i < arcnum;i++){
		int u,v;
		cin>>u>>v;
		p[u].push_back(v);
	}
	for(int i = 0;i < vexnum;i++)
	sort(p[i].begin(),p[i].end());
 	for(int i = 0 ;i < vexnum;i++)
	if(!vis[i])
	dfs(i);
	return 0;
}