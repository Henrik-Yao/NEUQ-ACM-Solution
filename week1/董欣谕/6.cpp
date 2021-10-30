#include <bits/stdc++.h>
using namespace std;
int a[100001],t[100001];
int main() {
	int n,T;
	cin>>n>>T;
	for (int i=1; i<=n; i++) {
		cin>>a[i]>>t[i];
		if (t[i]>T) a[i]=a[i]-(t[i]-T);
	}
	sort(a+1,a+1+n);
	cout<<a[n];
	return 0;
}
