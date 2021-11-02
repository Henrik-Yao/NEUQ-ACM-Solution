#include<bits/stdc++.h>
using namespace std;
const int N = 1e7+7;
int n,m,prime_cnt,prime[N];
bool not_prime[N];
void read(int &x){
	int f=1; x=0; char c=getchar();
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
	for(;c>='0'&&c<='9';c=getchar())	x=x*10+c-'0';
	x*=f;
}
void is_prime(int n) {
	prime_cnt = 0;
	not_prime[1] = true;
	for(int i=2; i<=n; ++i) {
		if(!not_prime[i]) prime[++prime_cnt] = i; 
		for(int j=1; j<=prime_cnt; ++j) {
			if(prime[j]*i > n) break;
			not_prime[prime[j]*i] = true;
			if(i%prime[j]==0) break;
		}
	}
}
int main() {
	read(n);
	is_prime(n);
	printf("%d\n",prime_cnt);
    return 0;
}

