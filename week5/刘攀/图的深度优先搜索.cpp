#include<bits/stdc++.h>
using namespace std;
int maps[51][2];
int check[20001];
int n,e;
void dfs(int m){
	if(check[m]) return;
	check[m]=1;
	cout<<m<<" ";
	int end=n;
	for(int i=0;i<e;i++){
		if(maps[i][0]==m&&check[maps[i][1]]==0) end=min(maps[i][1],end);
	}
	if(end!=n)
	dfs(end);
}
int main(){
	cin>>n>>e;
	for(int i=0;i<e;i++){
		cin>>maps[i][0];
		cin>>maps[i][1];
	}
	dfs(0);
	for(int i=1;i<n;i++){
		if(!check[i])
		dfs(i);
	}
}
