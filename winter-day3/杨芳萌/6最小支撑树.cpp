#include<bits/stdc++.h>
using namespace std;
const int N = 2333;
int n,m,fa[N];
 struct edge{
	int s,e,len;
}bian[123456];

void init(){ for(int i=1; i<=n; i++) fa[i] = i; }
int find(int x){
	if(fa[x]==x) return x;
	else return fa[x] = find(fa[x]);
}
void merge(int a,int b) { fa[find(a)] = find(b); }
bool cmp(edge a, edge b){ return a.len<b.len; } 
int kruskal(){
	sort(bian+1, bian+1+m, cmp);
	int ans = 0;
	int bianshu = 0; 
	for(int i=1; i<=m; i++){
		int s = bian[i].s;
		int e = bian[i].e;
		if(find(s)!=find(e)){
			ans += bian[i].len;
			merge(s,e);
			bianshu++;
		}
	}	
	if(bianshu!=n-1) return -1;
	return ans;
}

int main(){
	while(scanf("%d%d",&n,&m)!=EOF) {
		for(int i=1; i<=m; i++) scanf("%d%d%d", &bian[i].s,&bian[i].e,&bian[i].len);
		init();
		int ans = kruskal();
		if(ans==-1) puts("There is no minimum spanning tree.");
		else printf("%d\n",ans);
	}
	return 0;
}
