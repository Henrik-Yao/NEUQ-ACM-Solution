#include <bits/stdc++.h>
using namespace std;
int isnotprime[10000010];
int main() {
	int n;
	int cnt=0;
	memset(isnotprime,0,sizeof isnotprime);
	cin>>n;
	for (int i=2; i*i<=n; i++) {
		if (!isnotprime[i])
			for (int j=2*i; j<=n; j+=i)
				if (!isnotprime[j]) isnotprime[j]=1,cnt++;
	}
	cout<<n-cnt-1;
	return 0;
}
