#include <bits/stdc++.h>
using namespace std;
int isnotprime[10010],prime[10010];
int main() {
	int a,b;
	int cnt=0;
	memset(prime,0,sizeof prime);
	memset(isnotprime,0,sizeof isnotprime);
	isnotprime[1]=1;
	isnotprime[0]=1;
	for (int i=2; i<=10000; i++) {
		if (!isnotprime[i]) prime[++cnt]=i;
		for (int j=1; j<=cnt&&i*prime[j]<=10000; j++) {
			isnotprime[i*prime[j]]=1;
			if (i%prime[j]==0) break;
		}
	}
	while (cin>>a>>b) {
        int first=0;
		for (int i=a; i<=b; i++)
			if (!isnotprime[i]) {
                if (!first) cout<<i;
                else cout<<" "<<i;
                first=1;
            }
		cout<<endl;
	}
	return 0;
}
