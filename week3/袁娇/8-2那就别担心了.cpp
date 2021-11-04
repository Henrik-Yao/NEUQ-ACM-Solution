#include<bits/stdc++.h>
using namespace std;
int n,m;
int edge[501][501],dp[501],visit[501];
int dfs(int start){
	visit[start]=1;
	if(dp[start]) return dp[start];
	for(int i=1;i<=n;i++){
		if(edge[start][i])
		dp[start]+=dfs(i); 
	}
	return dp[start];
}
int main(){
	cin>>n>>m;
	edge[501][501]=0;dp[501]=0;visit[501]=0;
	int a,b; 
	while(m--){
		cin>>a>>b;
		edge[a][b]=1;
	}
	int start,end;
	cin>>start>>end;
	dp[end]=1;
	dfs(start);
	cout<<dp[start]<<" ";
	int flag=1;
	for(int i=1;i<=n;i++){
		if(visit[i]&&!dp[i]){
		
			flag=0;
			break;
		}
	}
	if(flag) cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
	return 0;
} 

