#include<bits/stdc++.h>
using namespace std;
int n,m,x,y,z,dis[110],pan[110],flag,minn,sum;
priority_queue<pair<int,int> >que;
vector<pair<int,int> >vec[110];
void dij(int xx){
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
			}
		}
	}
}
int main(){
	while(cin>>n>>m){
		minn=1e9;
		for(int i=0;i<n;i++)vec[i].clear();
		for(int i=1;i<=m;i++){
			cin>>x>>y>>z;
			vec[x].push_back(make_pair(y,z));
			vec[y].push_back(make_pair(x,z));
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++)dis[j]=1e6,pan[j]=0;
			dis[i]=0;
			sum=0;
			dij(i);
			//puts("233");
			for(int i=0;i<n;i++)sum+=dis[i];
			if(sum<minn){
				flag=i;
				minn=sum;
			}
		}
		cout<<flag<<endl;
	}
	return 0;
}
