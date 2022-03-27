#include <bits/stdc++.h>
using namespace std;
int vis[520],p[520],vec[520][520];
int n,m,count,a,b;
int dfs(int x){
	vis[x]=1;
	if(p[x]) return p[x];
	for(int i=1;i<=n;i++)
	if(vec[x][i])
	p[x]+=dfs(i);
	return p[x];
}
int main(){
int i;
cin>>n>>m;
for(i=1;i<=m;i++){
	cin>>a>>b;
	vec[a][b]=1;
}
cin>>a>>b;
p[b]=1;
int count=dfs(a);
int flag=1;
for(i=1;i<=n;i++){
	if(vis[i]&&!p[i]){
		flag=0;
		break;
	}
}
cout<<count;
if(!flag)
cout<<" No\n";
else cout<<" Yes\n";

return 0;

}
