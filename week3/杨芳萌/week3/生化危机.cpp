#include<bits/stdc++.h>
using namespace std;
int n,m,k,a[233],b[233],tmp,vis[233],s,t,fa[233];
void read(int &x) {
	int f=1; x=0; char c=getchar();
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
	for(;c>='0'&&c<='9';c=getchar())	x=x*10+c-'0';
	x*=f;
}
void init() { 
	for(int i=0; i<=m; i++) fa[i] = i; 
}
int find(int x) {
	if(fa[x]==x) return x;
	else return fa[x] = find(fa[x]);
}
void merge(int a,int b) {
	fa[find(a)] = find(b); 
}
bool ask(int a,int b) { 
	return find(a)==find(b); 
}

int main() {
	cin>>m>>n>>k;
	for(int i=1; i<=n; i++) {
		read(tmp);
		vis[tmp] = 1;
	}
	
	init();
	
	for(int i=1; i<=k; i++){
		read(a[i]), read(b[i]);
		if(vis[a[i]]==1&&vis[b[i]]==1) merge(a[i],b[i]);
	}
	
	read(s), read(t);
	
	for(int i=1; i<=k; i++) if(a[i]==s||b[i]==s) merge(a[i],b[i]);
	
	if(vis[t]==0) printf("The city %d is not safe!",t);
	else {
		if(ask(s,t)) printf("The city %d can arrive safely!",t);
		else printf("The city %d can not arrive safely!",t);
	}
	return 0;
}
