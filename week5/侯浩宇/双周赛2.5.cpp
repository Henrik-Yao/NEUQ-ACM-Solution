#include<bits/stdc++.h>
using namespace std;
bool p=0,p1[50005];
int n,m[50005],start;
void dfs(int s){
	if(p)return;
	if(m[s]==0){p=1;return;}
	if(s+m[s]<n&&p1[s+m[s]])p1[s+m[s]]=0,dfs(s+m[s]);
	if(s-m[s]>=0&&p1[s-m[s]])p1[s-m[s]]=0,dfs(s-m[s]);
	return;
}
int main(){
	cin>>n;
	for(int i=0;i<n;i++)
	cin>>m[i],p1[i]=1;
	cin>>start;
	dfs(start);
	if(p)cout<<"True";
	else cout<<"False";
	return 0;
}
