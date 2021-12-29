#include<bits/stdc++.h>
using namespace std;
bool s[2005][2005],p[2005][2005];
int sum=0;
void dfs(int a,int b){
	if(s[a-1][b])s[a-1][b]=0,dfs(a-1,b);
	if(s[a+1][b])s[a+1][b]=0,dfs(a+1,b);
	if(s[a][b-1])s[a][b-1]=0,dfs(a,b-1);
	if(s[a][b+1])s[a][b+1]=0,dfs(a,b+1);

	return;
}
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=0;i<=n+1;i++)
	for(int j=0;j<=m+1;j++)
	s[i][j]=0;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)	
	cin>>s[i][j],p[i][j]=1;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
	if(s[i][j]&&p[i][j]){dfs(i,j);sum++;}
	cout<<sum;
	return 0;
}
