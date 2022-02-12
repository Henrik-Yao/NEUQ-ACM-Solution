#include <bits/stdc++.h>
using namespace std;
int n,m;
int maxn=0;
int maxn1;
int ans;
int minn;
int flag=1; 
int p[100000];
struct node{
	int from;
	int to;
	int w;//ШЈжи 
};
node edge[100000];
bool cmp(node a,node b){
	return a.w<b.w;
}
void k(){
	sort(edge,edge+m,cmp);
	for(int i=1;i<=maxn;i++) p[i]=i;
	for(int i=0;i<m;i++){
		int p1=edge[i].from;
		int p2=edge[i].to;
		if(p[p1]!=p[p2]){
			ans+=edge[i].w;
			maxn1=max(p[p1],p[p2]);
			minn=min(p[p1],p[p2]);
			for(int j=1;j<=maxn;j++){
				if(p[j]==maxn1) p[j]=minn;
			}
			
		}
	}
	for(int i=1;i<=maxn;i++){
		if(p[i]!=1) flag=0;
	}
	if(flag)
	cout<<ans<<endl;
	else cout<<"There is no minimum spanning tree."<<endl;
} 
int main(){
	while(	cin>>n>>m){
	for(int i=0;i<m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		maxn=max(maxn,max(u,v));
		edge[i].from=u;
		edge[i].to=v;
		edge[i].w=w;
	}
	k();
	maxn=0;maxn1=0;ans=0;minn=0;memset(p,0,sizeof(p));
}
} 
