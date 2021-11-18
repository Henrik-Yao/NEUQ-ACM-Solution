#include <bits/stdc++.h>
using namespace std;
vector<int>a[20001];int vis[20001];
void dfs(int x){
	if(vis[x]) return;
	vis[x]=1;
	printf("%d ",x);
	
	int l=a[x].size();
	sort(a[x].begin(),a[x].end());
	for(int i=0;i<l;i++) dfs(a[x][i]);
}
int main(){
	int n,e;
	cin>>n>>e;
	while(e--){
		int a1,b;
		cin>>a1>>b;
		a[a1].push_back(b);
	}
	for(int i=0;i<n;i++){
		if(!vis[i]) dfs(i);
	}
	return 0;
}
