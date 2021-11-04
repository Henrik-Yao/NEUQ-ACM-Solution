#include<bits/stdc++.h>
using namespace std;
int flag=0,n,m,k,x,y,pan[210];
vector<int>vec[210];
void dfs(int fa,int x){
	if(x==y){
		flag=1;
		return;
	}
	int len=vec[x].size();
	for(int i=0;i<len;i++){
		if(vec[x][i]!=fa&&pan[vec[x][i]]==1)
		dfs(x,vec[x][i]);
	}
}
int main(){
	cin>>m>>n>>k;
	for(int i=1;i<=n;i++){
		scanf("%d",&x);
		pan[x]=1;
	}
	for(int i=1;i<=k;i++){
		scanf("%d%d",&x,&y);
		vec[x].push_back(y);
		vec[y].push_back(x);
	}
	cin>>x>>y;
	dfs(-1,x);
	if(pan[y]==0)printf("The city %d is not safe!",y);
	else if(flag==1)printf("The city %d can arrive safely£¡",y);
	else printf("The city %d can not arrive safely£¡",y);
	return 0;
}
