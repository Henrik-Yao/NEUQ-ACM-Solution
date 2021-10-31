#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;
	long long ans;
	while (cin>>n) {
		ans=0;
		for (int i=1; i<=n; i++)
			ans+=(ans+1)*2;
		cout<<ans<<endl;
	}
	return 0;
}
