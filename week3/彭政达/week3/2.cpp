#include<bits/stdc++.h>
using namespace std;
int g[600][600],y,ans[600],sum[600];
bool flag=true;
int dfs(int x)
{
	if(ans[x]!=-1) return ans[x];
	int t=0;
	for(int i=1;i<=sum[x];i++){
	 if(ans[g[x][i]]==-1)
         dfs(g[x][i]);
	 t+=ans[g[x][i]];
	}
	if(t==0) flag=0;
	return ans[x]=t;
}
int main()
{
	int n,m,x;
	cin>>n>>m;
	ios::sync_with_stdio(false);//	freopen("in.txt","r",stdin);	freopen("out.txt","w",stdout);
	memset(ans,-1,sizeof(ans));

	while(m--){
		cin>>x>>y;
		sum[x]++;
		g[x][sum[x]]=y;
	}
	cin>>x>>y;
	ans[y]=1;
	cout<<dfs(x)<<" ";
	if(flag) cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
    return 0;
}


