#include<bits/stdc++.h>
using namespace std;
long long n,a,b,c;
long long qp(long long x,long long y,long long mod){
	long long ans=1;
	while(y){
		if(y%2==1){
			y--;
			ans=((ans%mod)*(x%mod))%mod;
		}
		else{
			y/=2;
			x=((x%mod)*(x%mod))%mod;
		}
	}
	return ans;
}
int main(){
	scanf("%lld",&n);
	while(n--){
		scanf("%lld%lld%lld",&a,&b,&c);
		printf("%lld\n",qp(a,b,c));
	}
	return 0;
}
