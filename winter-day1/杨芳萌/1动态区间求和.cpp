#include<bits/stdc++.h>
#define int long long
#define lowbit(i) i&(-i)
using namespace std;
const int N = 1e6+6;
int n,q,a[N],c[N];

int update(int x,int value) {
	for(int i=x; i<=n; i+=lowbit(i)) c[i] += value;
}

int ask(int x) {
	int ans = 0;
	for(int i=x; i; i-=lowbit(i)) ans += c[i];
	return ans;
}

signed main() {
	cin>>n>>q;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		update(i,a[i]);
	}
	while(q--) {
		int op,l,r;
		cin>>op>>l>>r;
		if(op==1) update(l,r);
		else cout<<ask(r)-ask(l-1)<<endl;
	}
	return 0;
}
