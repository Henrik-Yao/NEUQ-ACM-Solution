#include<bits/stdc++.h>
using namespace std;
#define N 100010
long long n,m,x,y,z,dis[N],pan[N],top[N],sta[N],fa[N],cnt=0;
vector<pair<int,int> >vec[N];
priority_queue<pair<int,int> >que;
void dij(int xx){
	for(int i=0;i<n;i++)dis[i]=1e9,pan[i]=0,fa[i]=i;
	dis[xx]=0;
	top[xx]=1;
	que.push(make_pair(0,xx));
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
				fa[v]=u;
			}
		}
	}
}
void dfs(int x){
	cnt++;
	sta[cnt]=x;
	if(fa[x]!=x)dfs(fa[x]);
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=m/2;i++){
		cin>>x>>y>>z;
		vec[x].push_back(make_pair(y,z));
		vec[y].push_back(make_pair(x,z));
	}
	while(cin>>x>>y){
		cnt=0;
		dij(x);
		//puts("233");
		dfs(y);
		if(x==y){
			cout<<x<<"-->"<<y;
		}
		else
		for(int i=cnt;i>=1;i--){
			if(i==cnt)cout<<sta[i];
			else cout<<"-->"<<sta[i];
		}
		cout<<':'<<dis[y]<<endl;
	}
	
	return 0;
}
