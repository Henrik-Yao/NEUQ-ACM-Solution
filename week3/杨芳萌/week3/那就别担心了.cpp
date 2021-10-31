#include<bits/stdc++.h>
using namespace std;
const int N = 555;
int n,m,first[N],cnt,a,b,flag,ans[N];
void read(int &x){
	int f=1; x=0; char c=getchar();
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
	for(;c>='0'&&c<='9';c=getchar())	x=x*10+c-'0';
	x*=f;
}

struct edge{
	int end,nxt;
}bian[300010];

void addedge(int s,int e){
	cnt++;
	bian[cnt].end = e;
	bian[cnt].nxt = first[s];
	first[s] = cnt;
}

void dfs(int s) {
	if(ans[s]!=-1)	return;
	
	if(s==b) { 
		ans[s] = 1;
		return; 
	} 
	
	if(first[s]==0) {
		ans[s]=0;
		flag = 1;
		return;
	}
	
	ans[s] = 0;
	for(int i=first[s]; i>0; i=bian[i].nxt) {
		int e = bian[i].end;
		dfs(e);
		ans[s] += ans[e];
	}
	return;
}

int main(){
	read(n), read(m);
	for(int i=1; i<=m; i++) {
		int s, e;
		read(s), read(e);
		addedge(s,e);
	}
	for(int i=1; i<=n; i++) ans[i] = -1;
	read(a), read(b);
	dfs(a);
	if(flag==0) printf("%d Yes\n",ans[a]);
	else printf("%d No\n",ans[a]);
    return 0;
}
