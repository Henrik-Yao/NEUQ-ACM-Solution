#include <bits/stdc++.h>
using namespace std;
const int maxn=10001;
vector<int> A[maxn];
int main(){
	int n,m,k;
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int u,v;
		cin>>u>>v;
		A[u].push_back(v);
		A[v].push_back(u);
	}
	cin>>k;
	while(k--){
		int Np,p;
		bool vis[maxn]={false};
		cin>>Np;
		while(Np--){
			cin>>p;
			vis[p]=true;
		}
	bool ok=true;
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			for(int j=0;j<A[i].size();j++){
				if(!vis[A[i][j]])
				ok=false;
			}
		}
	}
	if(ok)
	cout<<"YES\n";
	else cout<<"NO\n";

}

return 0;

}
