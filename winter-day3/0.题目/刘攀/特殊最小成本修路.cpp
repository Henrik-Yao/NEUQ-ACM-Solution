#include<bits/stdc++.h>
using namespace std;
int a,b,c;
int p[1000];
struct node{
	int from;
	int to;
	int cost;
};
bool cmp(node a,node b){
	return a.cost<b.cost;
}
int find(int x){
	if(p[x]==-1) return x;
	p[x]=find(p[x]);
	return p[x];
}
node s[1000];
int main(){
	int n,v,e;
	while(cin>>n>>v>>e){
		for(int i=0;i<e;i++){
			cin>>a>>b>>c;
			s[i].from=a;
			s[i].to=b;
			s[i].cost=c;
		}
		sort(s,s+e,cmp);
		int visit[1000];
		memset(visit,0,sizeof(visit));
		memset(p,-1,sizeof(p));
		int sum=0;
		int i,j;
		for(i=0,j=0;i<e;i++){
			int v1=find(s[i].from);
			int v2=find(s[i].to);
			if(v1!=v2){
				if((s[i].from==v||s[i].to==v)&&visit[v]>=2) continue;
				visit[s[i].from]++;
				visit[s[i].to]++;
				p[v2]=v1;
				j++;
				sum+=s[i].cost;
		}
	}
		if(j==n-1) cout<<sum<<endl;
		else cout<<-1<<endl;
}
}
