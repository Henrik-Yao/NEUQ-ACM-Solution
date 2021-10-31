#include<bits/stdc++.h>
using namespace std;
int vis[1000];
int road[1000][1000];
int be,e,m,n,k;
int ans=0;
void dfs(int start){
	if(start==e){
		ans++;
		return;
	}
	for(int i=0;i<=e;i++){
		if(road[start][i]==1&&vis[i]!=0)dfs(i);
	}
}
int main(){
	cin>>m>>n>>k;
	int count=0;
	for(int i=0;i<n;i++){
		int a;
		cin>>a;
		vis[a]=1;
	}
	for(int i=0;i<k;i++){
		int a,b;
		cin>>a>>b;
		road[a][b]=1;
		road[b][a]=1;
	}
	cin>>be>>e;
	if(vis[e]==0){
		printf("The city %d is not safe!",e);
		return 0;
	}
	else dfs(be);
	if(ans==0){
		printf("The city %d can not arrive safely£¡",e);
	}
	else{
		printf("The city %d can arrive safely£¡",e);
	}
	return 0;
}
