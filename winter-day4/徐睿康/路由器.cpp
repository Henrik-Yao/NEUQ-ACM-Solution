#include<bits/stdc++.h>
using namespace std;
int n,m,x,y,k,dis[210],pan[210];
priority_queue<pair<int,int> >que;
vector<pair<int,int> >vec[210];
void dij(int x){
	for(int i=0;i<n;i++)dis[i]=1e9,pan[i]=0;
	dis[x]=0;
	que.push(make_pair(0,x));
	while(que.size()){
		int u=que.top().second;
		que.pop();
		if(pan[u])continue;
		pan[u]=1;
		for(int i=0;i<vec[u].size();i++){
			int v=vec[u][i].first,w=vec[u][i].second;
			if(dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				que.push(make_pair(-dis[v],v));
			}
		}
	}
}
int main(){
	while(cin>>n>>m){
		for(int i=0;i<n;i++)vec[i].clear();
		for(int i=1;i<=n;i++){
			cin>>x>>k;
			for(int j=1;j<=k;j++){
				cin>>y;
				vec[x].push_back(make_pair(y,1));
			}
		}
		for(int i=1;i<=m;i++){
			cin>>x>>y;
			dij(x);
			if(dis[y]!=1e9)cout<<dis[y]<<endl;
			else cout<<"connection impossible"<<endl;
		}
	}
	return 0;
}
