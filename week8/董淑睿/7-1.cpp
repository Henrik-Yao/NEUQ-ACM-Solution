/*
 * @Author: ComplexPug
 * @Email: 3010651817@qq.com
 * @Date: 2021-12-05 23:26:23
 * @LastEditTime: 2021-12-05 23:31:59
 */
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int _=1e5+7;
const int oo=0x3f3f3f3;
int read() {
	int x=0,f=1;char s=getchar();
	for(;s>'9'||s<'0';s=getchar()) if(s=='-') f=-1;
	for(;s>='0'&&s<='9';s=getchar()) x=x*10+s-'0';
	return x*f;
}
struct node {
	int l,r;
	bool operator < (const node &b) const {
		return l<b.l;
	}
} a[1010];
int n,f[1011];
void solve() {
	n=read();
	for(int i=1;i<=n;++i) {
		a[i].l=read();
		a[i].r=read();
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;++i) f[i]=0;
	for(int i=1;i<=n;++i) {
		for(int j=0;j<=i;++j) {
			if(a[j].r<=a[i].l) {
				f[i]=max(f[i],f[j]+1);
			}
		}
	}
	int ans=0;
	for(int i=1;i<=n;++i) {
		ans=max(ans,f[i]);
	}
	cout<<n-ans<<"\n";
}
int main() {
	int T=read();
	while(T-->0) {
		solve();
	}
	return 0;
}