#include<bits/stdc++.h>
using namespace std;
int n,m,x,y,t,tt,flag,pan[10010];
vector<int>vec[10010];
void dfs(int x){
	int len=vec[x].size();
	for(int i=0;i<len;i++){
		if(pan[vec[x][i]]==0)flag=1;
	}
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		cin>>x>>y;
		vec[x].push_back(y);
		vec[y].push_back(x);
	}
	cin>>t;
	while(t--){
		cin>>tt;
		while(tt--){
			cin>>x;
			pan[x]=1;
		}
		flag=0;
		for(int i=1;i<=n;i++)
			if(pan[i]==0)
				dfs(i);
		if(flag==1)puts("NO");
		else puts("YES");
		memset(pan,0,sizeof(pan));
	}
	return 0;
}
