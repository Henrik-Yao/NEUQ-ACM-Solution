#include <bits/stdc++.h>
using namespace std;
int a[10001],f[10001];
int main(){
	int n,i;
	cin>>n;
	int cnt=0;
	for (int i=1;i<=n;i++){
		cin>>a[i],f[i]=a[i];
		if (f[i]<0) cnt++;
	}
	if (cnt==n) {
		cout<<0;
		return 0;
	}
	for (i=1;i<=n;i++){
		f[i]=max(f[i-1]+a[i],a[i]);
	}
	int ans=-0x3f3f3f3f;
	for (i=1;i<=n;i++)
		ans=max(ans,f[i]);
	cout<<ans;
	return 0;
}
