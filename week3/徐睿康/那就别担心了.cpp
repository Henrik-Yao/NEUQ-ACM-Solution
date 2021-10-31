#include<bits/stdc++.h>
using namespace std;
vector<int >vec[510];
int n,m,x,y,u,v,flag=0,len,mem[510];
int dfs(int x){
	if(x==v){
		return mem[x]=1;
	}
	if(mem[x]!=-1){
		return mem[x];
	}
	len=vec[x].size();
	if(len==0)flag=1;
	int ans=0;
	for(int i=0;i<vec[x].size();i++){
		ans+=dfs(vec[x][i]);
	}
	return mem[x]=ans;
}
int main(){
	cin>>n>>m;
	memset(mem,-1,sizeof(mem));
	for(int i=1;i<=m;i++){
		scanf("%d%d",&x,&y);
		vec[x].push_back(y);
	}
	cin>>u>>v;
	printf("%d ",dfs(u));
	if(flag==1)printf("No");
	else printf("Yes");
	return 0;
}
