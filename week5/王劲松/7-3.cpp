#include<bits/stdc++.h>
using namespace std;
int n,e;
vector<int>tu[20010];
int vi[20010];
void dfs(int n);

int main(){
	cin>>n>>e;
	int i,a,b;
	memset(vi,0,sizeof(vi));
	for(i=0;i<e;i++){
		cin>>a>>b;
		tu[a].push_back(b);
	}
	for(i=0;i<n;i++){
		if(tu[i].size()!=0)sort(tu[i].begin(),tu[i].end());
	}
	for(i=0;i<n;i++){
		if(vi[i])continue;
		else dfs(i);
	}
	return 0;
}
void dfs(int q){
	cout<<q<<" ";
	vi[q]=1;
	int cnt=tu[q].size();
	int num=0;
	for(;num<cnt;num++){
		if(!vi[tu[q][num]])dfs(tu[q][num]);
	}
}
