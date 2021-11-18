#include<bits/stdc++.h>
using namespace std;
int isprime(int n){
	if(n==2) return 1;
	for(int i=2;i<=sqrt(n);i++){
		if(n%i==0) return 0;
	}
	return 1;
}
int main(){
	int N,a;
	cin>>N;
	while(N--){
		cin>>a;
		if(a%2==0) cout<<2<<endl;
		else if(isprime(a)) cout<<1<<endl;
		else if(isprime(a-2)) cout<<2<<endl;
		else cout<<3<<endl;
	}
	return 0;
}
