#include <bits/stdc++.h>
using namespace std;
const int maxn=1e8+1;
int n;
bool check(int x) {
	if (x<=1) return 0;
	for (int i=2; i<=sqrt(x); i++)
		if (x%i==0) {
			return 0;
		}
	return 1;
}
int main() {
	int t,n;
	cin>>t;
	while (t--) {
		scanf("%d",&n);
		if (n%2==0) {
			cout<<2<<endl;
			continue;
		}
		if (check(n)) {
			cout<<1<<endl;
			continue;
		}
		if (check(2)&&check(n-2)) {
			cout<<2<<endl;
			continue;
		}
		cout<<3<<endl;

	}
	return 0;
}
