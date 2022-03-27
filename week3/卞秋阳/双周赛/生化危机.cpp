#include<bits/stdc++.h>
#define INF 0x3f3f3f3f3f
using namespace std;
int m,n,k,x,p,q,v,t,y,flag=0;int a[60],vis[110],c[110][110];
bool b[110];
void dfs(int v){
	if(v==y){
		flag=1;return;
	}
	for(int i=1;i<=m;i++){
		if(!b[i]||vis[i]||c[v][i]==0) continue;
		vis[i]=1;
		dfs(i);
		vis[i]=0;
	}
	return;
	
}

int main()
{ cin>>m>>n>>k;
  for(int i=1;i<=n;i++)
  {
  	cin>>x;
  	b[x]=1;
  } 
  memset(c,0,sizeof(c));
  for(int i=1;i<=k;i++)
  {
  	cin>>p>>q;
  	c[p][q]=1;
  	c[q][p]=1;
  }
  cin>>t>>y;
  if(b[y]==0) {
  cout<<"The city "<<y<<" is not safe!";
  return 0;}
  dfs(t);
  if(flag==0) cout<<"The city "<<y<<" can not arrive safely£¡";
  else        cout<<"The city "<<y<<" can arrive safely£¡";

    return 0;
}

