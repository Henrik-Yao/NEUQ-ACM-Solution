#include <bits/stdc++.h> 
using namespace std;
struct Edge{
	int t;
	int h;
	int cost;
}edge[1200];
bool cmp(Edge a,Edge b){
	return a.cost<b.cost;
}
int f[1200];
int find(int x){
	if(f[x]==-1) return x;
	f[x]=find(f[x]);
	return f[x];
}
int main(){
	int n,v,e;
	while(cin>>n>>v>>e){
		for(int i=0;i<e;i++){
			cin>>edge[i].t>>edge[i].h>>edge[i].cost;
		}
		sort(edge,edge+e,cmp);
		int visit[n];
		memset(visit,0,sizeof(visit));
		memset(f,-1,sizeof(f));
		int sum=0,i,j;
		for(i=0,j=0;i<e&&j<n-1;i++){
			int t1=find(edge[i].t);
			int h1=find(edge[i].h);
			if(t1!=h1){
				if((edge[i].t==v||edge[i].h==v)&&visit[v]>=2) continue;
				visit[edge[i].t]++;
				visit[edge[i].h]++;
				f[h1]=t1;
				j++;
				sum+=edge[i].cost;	
			}	
		}
		if(j==n-1) cout<<sum<<endl;
		else cout<<-1<<endl;
	}
	return 0;
}
