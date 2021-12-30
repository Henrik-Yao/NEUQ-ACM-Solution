#include<bits/stdc++.h>
using namespace std;
const int MIN = -0x7fffffff;
const int N = 2333;
int n,m,q,fa[N];
void read(int &x){
	int f=1; x=0; char c=getchar();
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
	for(;c>='0'&&c<='9';c=getchar())	x=x*10+c-'0';
	x*=f;
}
void init(){
	for(int i=1; i<=n; i++) fa[i] = i;
}
int find(int x){
	if(fa[x]==x) return x;
	else return fa[x] = find(fa[x]);
}
void merge(int a,int b){
	fa[find(a)] = find(b);
}
bool ask(int a,int b){	 
	return find(a)==find(b);
}
int main() {
	read(n), read(m), read(q);
	init();
	for(int i=1; i<=m; i++){
		int a,b;
		cin>>a>>b;
		merge(a,b);
	}	
	while(q--) {
		int a,b;
		read(a), read(b); 
		if(ask(a,b)) puts("In the same gang.");
		else puts("In different gangs.");
	}
	int ans = 0;
	for(int i=1; i<=n; i++) if(find(i)==i) ans++;
	printf("%d\n",ans);
 	return 0;
}
