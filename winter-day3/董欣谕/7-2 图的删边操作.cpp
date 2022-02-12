#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pii pair<int,int>
const int mod=1e9+7;
const int INF=0x3f3f3f3f;
map<int,map<int,int>>mp;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int n,e;
	cin>>n>>e;
	for (int i=1;i<=e;i++){
		int u,v,w;
		cin>>u>>v>>w;
		mp[u][v]=w;
	}
	int k;
	cin>>k;
	for (int i=1;i<=k;i++){
		int a,b;
		cin>>a>>b;
		mp[a].erase(b);
	}
	for (auto i:mp){
		if (!i.second.empty()) cout<<i.first<<":";
		for (auto j:i.second){
			cout<<"("<<i.first<<","<<j.first<<","<<j.second<<")";
		}
		if (!i.second.empty()) cout<<endl;
	}
	return 0;
} 
