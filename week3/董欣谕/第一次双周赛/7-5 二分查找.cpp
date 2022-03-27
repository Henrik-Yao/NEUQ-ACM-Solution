#include <bits/stdc++.h>
using namespace std;
int a[1000001];
int main(){
	int n,m;
	cin>>n>>m;
	for (int i=1;i<=n;i++)
		cin>>a[i];
	int pos=lower_bound(a+1,a+1+n,m)-a;
	if (pos!=-1) cout<<pos;
	else cout<<n+1;
	return 0;
}
