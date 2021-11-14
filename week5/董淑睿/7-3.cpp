#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int _=4e5+7;
int read() {
	int x=0,f=1;char s=getchar();
	for(;s>'9'||s<'0';s=getchar()) if(s=='-') f=-1;
	for(;s>='0'&&s<='9';s=getchar()) x=x*10+s-'0';
	return x*f;
}
int n,m,vis[_];
std::vector<int> G[_];
void dfs(int u) {
	vis[u]=1;
	cout<<u-1<<" ";
	for(auto x:G[u]) {
		if(!vis[x]) {
			dfs(x);
		}
	}
}
int main() {
	n=read(),m=read();
	for(int i=1;i<=m;++i) {
		int x=read()+1,y=read()+1;
		G[x].push_back(y);
	}
	for(int i=1;i<=n;++i) sort(G[i].begin(),G[i].end());
	for(int i=1;i<=n;++i) {
		if(!vis[i]) dfs(i);
	}
	return 0;
}

