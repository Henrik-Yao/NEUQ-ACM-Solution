#include <bits/stdc++.h>
using namespace std;
int x[1000001],val1[1000001]= {0},val2[1000001]= {0},Max=-0x3f3f3f3f;
set<int> s1,s2;
int main() {
	int i,n;
	cin>>n;
	for (i=1; i<=n; i++) {
		cin>>x[i];
		if (s1.count(x[i])==0) {
			s1.insert(x[i]);
			val1[i]=val1[i-1]+1;
		} else val1[i]=val1[i-1];
	}
	for (i=n; i>=1; i--) {
		if (s2.count(x[i])==0) {
			s2.insert(x[i]);
			val2[i]=val2[i+1]+1;
		} else val2[i]=val2[i+1];
	}
	for (i=1; i<=n-1; i++) {
		int sum=val2[i+1]+val1[i];
		Max=max(Max,sum);
	}
	cout<<Max;
	return 0;
}
