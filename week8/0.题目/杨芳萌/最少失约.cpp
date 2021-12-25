#include<bits/stdc++.h>
using namespace std;
int n,T,f[233];
void read(int &x){
	int f=1; x=0; char c=getchar();
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
	for(;c>='0'&&c<='9';c=getchar())	x=x*10+c-'0';
	x*=f;
}
struct node{ int l,r; } a[233];
bool cmp(node a, node b) { return a.l<b.l; }
int main(){
	read(T);
	while(T--) {
		int ans = 0;
		read(n);
		for(int i=1; i<=n; i++) read(a[i].l),read(a[i].r);
		sort(a+1,a+1+n,cmp); 
		for(int i=1; i<=n; i++) f[i] = 1;
		for(int i=1; i<=n; i++) {
			int maxn = 0;
			for(int j=i; j>=1; j--) 
				if(a[j].r<=a[i].l && f[j]>maxn) maxn = f[j];
			f[i] = maxn+1;
			ans = max(ans, f[i]);
		}
		printf("%d\n",n-ans);
	} 
    return 0;
}

