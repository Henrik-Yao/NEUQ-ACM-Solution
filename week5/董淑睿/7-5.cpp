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
int n,S,a[_],vis[_];
vector<int> G[_];
map<int,int> dsr;
void dfs(int u) {
	vis[u]=1;
	if(dsr[u]) {
		cout<<"True";
		exit(0);
	}
	for(auto x:G[u]) {
		if(!vis[x]) {
			dfs(x);
		}
	}
}
int main() {
	// freopen("a.in","r",stdin);
	n=read();
	for(int i=1;i<=n;++i) {
		a[i]=read();
		if(!a[i]) {
			dsr[i]=1;
		} else {
			if(i+a[i]<=n) {
				G[i].push_back(i+a[i]);
			}
			if(i-a[i]>=1) {
				G[i].push_back(i-a[i]);
			}
		}
	}
	S=read()+1;
	dfs(S);
	// for(int i=1;i<=n;++i) cout<<vis[i]<<" ";
	// for(int i=1;i<=n;++i) cout<<dsr[i]<<" ";
	cout<<"False";
	return 0;
}