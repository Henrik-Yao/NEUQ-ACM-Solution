#include<bits/stdc++.h>
using namespace std;
const int N = 23333;
int n,m,prime_cnt,prime[N];
bool not_prime[N];

void is_prime(int n) {
	prime_cnt = 0;
	not_prime[1] = true;
	for(int i=2; i<=m; ++i) {
		if(!not_prime[i]) prime[++prime_cnt] = i; 
		for(int j=1; j<=prime_cnt; ++j) {
			if(prime[j]*i > n) break;
			not_prime[prime[j]*i] = true;
			if(i%prime[j]==0) break;
		}
	}
}
int main() {
	while(cin>>n>>m) {
		is_prime(m);
		for(int i=1; i<=prime_cnt; i++) 
			if(prime[i]>=n) {
			if(i!=prime_cnt) cout<<prime[i]<<' ';
			else cout<<prime[i]<<endl;
		} 
	}
    return 0;
}

