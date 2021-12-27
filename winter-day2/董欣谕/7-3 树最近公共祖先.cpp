#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pii pair<int,int>
const int mod=1e9+7;
const int INF=0x3f3f3f3f;
int dep[101],fa;
int p[101][9];
struct edge{
	int to;
	int next;
}ed[1001];
int head[101],cnt=0;
void add(int u,int v){
	ed[++cnt].to=v;
	ed[cnt].next=head[u];
	head[u]=cnt;
}
void dfs(int u,int fa){
	//cout<<u<<" "<<fa<<endl;
	dep[u]=dep[fa]+1;
	p[u][0]=fa;
	for (int i=1;(1<<i)<=dep[u];i++)
		p[u][i]=p[p[u][i-1]][i-1];
	for (int i=head[u];i;i=ed[i].next){
		int v=ed[i].to;
		if (v!=fa) dfs(v,u);
	}
}
int lca(int a,int b){
	if(dep[a]>dep[b]) swap(a,b);
	for (int i=7;i>=0;i--)
		if (dep[a]<=dep[b]-(1<<i))
			b=p[b][i];
	if (a==b) return a;
	for (int i=7;i>=0;i--){
		if (p[a][i]==p[b][i]) continue;
		else a=p[a][i],b=p[b][i];
	}
	return p[a][0];
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int t;
	cin>>t;
	while (t--){
		memset(dep,0,sizeof dep);
		memset(ed,0,sizeof ed);
		memset(p,0,sizeof p);
		stack<int>st;
		int x,fa;
		cin>>x;
		fa=x;
		st.push(x);
		while (!st.empty()){
			cin>>x;
			if (x){
				//add(x,st.top());
				add(st.top(),x);
				st.push(x);
			}
			else {
				st.pop();
			}
		}
		dfs(fa,0);
		cin>>x;
		int a,b;
		cin>>a>>b;
		cout<<lca(a,b)<<endl;
	}
	return 0;
} 
