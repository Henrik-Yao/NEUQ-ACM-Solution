#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pii pair<int,int>
const int mod=1e9+7;
const int INF=0x3f3f3f3f;
int f[1001][1001],path[1001][1001];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int n,m;
	memset(f,INF,sizeof f);
	cin>>n>>m;
	for (int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		f[u][v]=w;
		path[u][v]=v;
	}
	for (int k=0;k<n;k++){
		for (int i=0;i<n;i++)
			for (int j=0;j<n;j++){
				if (i==j||i==k||j==k) continue;
				if (f[i][j]>f[i][k]+f[k][j]){
					f[i][j]=f[i][k]+f[k][j];
					path[i][j]=path[i][k];
				}
			}
	}
	for (int i=1;i<=2;i++){
		int a,b;
		cin>>a>>b;
		if (a==b){
			cout<<a<<"->"<<b<<":"<<0<<endl;
			continue;
		}
		int u=a;
		if (f[a][b]!=INF) {
			cout<<a;
			while (u!=b){
				cout<<"->"<<path[u][b];
				u=path[u][b];
			}
			cout<<":"<<f[a][b]<<endl;
		}
		else cout<<a<<"->"<<b<<":"<<-1<<endl;
	}
	int ans=-1,start,end;
	for (int i=0;i<n;i++)
		for (int j=0;j<n;j++)
			if(f[i][j]!=INF){
				if (ans<f[i][j]){
					ans=f[i][j];	
					start=i,end=j;
				}
			}
	int u=start;
	cout<<start;
	while (u!=end){
		cout<<"->"<<path[u][end];
		u=path[u][end];
	}
	cout<<":"<<ans;
	return 0;
} 
