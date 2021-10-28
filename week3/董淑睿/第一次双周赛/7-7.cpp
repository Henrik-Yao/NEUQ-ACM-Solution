#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int _=1e6+7;
int read() {
	int x=0,f=1;char s=getchar();
	for(;s>'9'||s<'0';s=getchar()) if(s=='-') f=-1;
	for(;s>='0'&&s<='9';s=getchar()) x=x*10+s-'0';
	return x*f;
}
int a[_],n,b[_],lsh[_],tot;
int lowbit(int x) {
	return x & (-x);
}
void add(int x,int val) {
	if(x<=0) return;
	for(int i=x;i<=n;i+=lowbit(i))
		a[i]+=val;
}
int sum(int x) {
	int ans=0;
	if(x==0) return 0;
	for(int i=x;i>=1;i-=lowbit(i))
		ans+=a[i];
	return ans;
}
int main() {
	n=read();
	for(int i=1;i<=n;++i) {
		lsh[++tot]=b[i]=read();
	}
	sort(lsh+1,lsh+1+tot);
	tot=unique(lsh+1,lsh+1+n)-lsh-1;
	for(int i=1;i<=n;++i) {
		b[i]=lower_bound(lsh+1,lsh+1+tot,b[i])-lsh;
		// cout<<b[i]<<" "<<"!\n";
	}
	ll tot=0;
	for(int i=1;i<=n;++i) {
		tot+=i-1-sum(b[i]);
		// cout<<sum(b[i])<<"< ";
		add(b[i],1);
		// add(b[i]-1,-1);
		// cout<<b[i]<<" : ad" <<1<<"\n";
		// for(int j=1;j<=n;++j) cout<<sum(j)<<" ";cout<<"\n";
	}
	cout<<tot;
	return 0;
}
