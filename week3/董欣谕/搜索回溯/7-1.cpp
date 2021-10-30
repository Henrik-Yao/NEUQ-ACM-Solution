#include <bits/stdc++.h>
using namespace std;
int n,m,k,d,s,flag=0;
vector <int> r[101];
int vis[101],safe[101];
void dfs(int x){
	if (flag==1) return;
	if (x==d) {
		flag=1;
		printf("The city %d can arrive safely!",d);
		return;
	}
	for (int i=0;i<r[x].size();i++){
		if (!vis[i]){
			vis[i]=1;
			dfs(r[x][i]);
			vis[i]=0; 
		}
	}
} 
int main(){
	memset(vis,0,sizeof vis);
	memset(safe,0,sizeof safe);
	cin>>m>>n>>k;
	for (int i=1;i<=n;i++){
		int x;
		cin>>x;
		safe[x]=1;
	}
	for (int i=1;i<=k;i++){
		int u,v;
		cin>>u>>v;
		r[u].push_back(v);
		r[v].push_back(u);
	}
	cin>>s>>d;
	if (safe[d]==0) {
		printf("The city %d is not safe!",d);
		return 0;
	}
	dfs(s);
	if (flag==0) printf("The city %d can not arrive safely!",d);
	return 0;
}
