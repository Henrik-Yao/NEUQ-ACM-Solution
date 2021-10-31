#include<bits/stdc++.h>
using namespace std;
int m,n,k,s1,s2,t,y,flag=0;int a[600],vis[110],c[600][600];
int ans=0;
bool b[110];
int dfs(int v){
    if(a[v]) return a[v];
	int sum=0;
	for(int i=1;i<=n;i++){
		if(c[v][i]==0) continue;
		if(a[i]);
		else{
			dfs(i);
			
		}
		sum=sum+a[i];
	}

if(sum==0) flag=1;
		return a[v]=sum;
}

int main()
{ cin>>n>>m;
  memset(c,0,sizeof(c));
  for(int i=1;i<=m;i++)
  {
  	cin>>s1>>s2;
  	c[s1][s2]=1;
  }
  cin>>t>>y;
  a[y]=1;
  ans=dfs(t);
  cout<<ans;
 
  if(flag==1) cout<<" No";
  else cout<<" Yes";
    
}
