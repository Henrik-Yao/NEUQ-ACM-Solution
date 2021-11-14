#include<bits/stdc++.h>
using namespace std;
const int N = 23333;
int n,cnt,m;
bool vis[N];
vector<int> G[N];
void read(int &x){
	int f=1; x=0; char c=getchar();
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
	for(;c>='0'&&c<='9';c=getchar())	x=x*10+c-'0';
	x*=f;
}
void dfs(int u){//±éÀúÍ¼ 
	printf("%d ",u);
	vis[u]=1;
	for(int i=0;i<G[u].size();i++){
		int v=G[u][i];
		if(vis[v]) 	continue;
		dfs(v);
	}
}

int main(){
	read(n), read(m);
	for(int i=1; i<=m; i++) {
		int s,e;
		read(s),read(e);
		G[s].push_back(e);
	}
	for(int i=0; i<n; i++) sort(G[i].begin(),G[i].end());
	for(int i=0; i<n; i++) if(vis[i]==0) { vis[i] = 1; dfs(i);} 
    return 0;
}
