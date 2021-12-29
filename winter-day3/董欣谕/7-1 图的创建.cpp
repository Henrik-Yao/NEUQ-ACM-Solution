#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pii pair<int,int>
const int mod=1e9+7;
const int INF=0x3f3f3f3f;
struct edge{
	int to;
	int from;
	int w;
}ed[20001];
int cnt=0;
void add(int u,int v,int w){
	ed[++cnt].to=v;
	ed[cnt].from=u;
	ed[cnt].w=w;
}
bool cmp(edge a,edge b){
	if (a.from!=b.from)return a.from<b.from;
	else return a.to<b.to; 
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int n,e;
	cin>>n>>e;
	for (int i=1;i<=e;i++){
		int u,v,w;
		cin>>u>>v>>w;
		add(u,v,w);
	}
	sort(ed+1,ed+1+e,cmp);
	int last=-1;
	for (int i=1;i<=e;i++){
		if (ed[i].from!=last){
			if(last!=-1) cout<<endl;
			cout<<ed[i].from<<":";
			last=ed[i].from;
		}
		cout<<"("<<ed[i].from<<","<<ed[i].to<<","<<ed[i].w<<")";
	}
	return 0;
} 
