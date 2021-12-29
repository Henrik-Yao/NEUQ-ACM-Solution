#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pii pair<int,int>
const int mod=1e9+7;
const int INF=0x3f3f3f3f;
struct edge{
	int to;
	int next;
}ed[101];
int in[101],head[101],cnt=0;
int n,m;
void add(int u,int v){
	ed[++cnt].to=v;
	ed[cnt].next=head[u];
	head[u]=cnt;
}
int topsort(){
	int flag=0;
	queue<int>q;
	for (int i=1;i<=n;i++)
		if (in[i]==0) q.push(i);
	while (!q.empty()){
		if (q.size()>1) flag=1;
		int cur=q.front();
		q.pop();
		for (int i=head[cur];i;i=ed[i].next){
			int v=ed[i].to;
			in[v]--;
			if (in[v]==0) q.push(v);
		}
	}
	for (int i=1;i<=n;i++)
		if (in[i]) return 0;
	if (!flag) return 1;
	else return 2;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	while (cin>>n>>m){
		memset(ed,0,sizeof ed);
		memset(in,0,sizeof in);
		for (int i=1;i<=m;i++){
			int u,v;
			cin>>u>>v;
			in[v]++;
			add(u,v);
		}
		cout<<topsort()<<endl;
	}	
	return 0;
} 
