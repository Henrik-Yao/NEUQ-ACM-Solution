#include<bits/stdc++.h>
using namespace std;
int m,i,a[100000];
int vi[100000];
int flag=0;
void dfs(int s);
int main(){
	cin>>m;
	for(i=0;i<m;i++){
		cin>>a[i];
	}
	int s;
	cin>>s;
	dfs(s);
	if(!flag)cout<<"False";
	else cout<<"True";
	return 0;
}
void dfs(int s){
	if(a[s]==0){
		flag=1;
		return;
	}
	if(flag==1)return;
	vi[s]=1;
	if(s+a[s]<m&&s+a[s]>=0&&!vi[s+a[s]])dfs(s+a[s]),vi[s+a[s]]=0;
	if(s-a[s]<m&&s-a[s]>=0&&!vi[s-a[s]])dfs(s-a[s]),vi[s-a[s]]=0;
}
