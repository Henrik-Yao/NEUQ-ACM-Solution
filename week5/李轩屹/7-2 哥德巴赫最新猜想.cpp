#include <bits/stdc++.h>
using namespace std;
const int maxn=1e7+10;
int t,n;
int prime(int n){
	bool p=1;
	for(int i=2;i<=sqrt(n);i++){
		if(n%i==0){
			p=0;
			break;
		}
	}
	return p;
}
int main(){
	cin>>t;
	while(t--){
		cin>>n;
		if(n%2==0) cout<<2;
		else{
			if(prime(n)) cout<<1;
			else{
				if(prime(n-2)) cout<<2;
				else cout<<3;
			}
		}
		cout<<endl;
	} 
    return 0;
}




