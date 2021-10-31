#include<bits/stdc++.h>
using namespace std;

long long n,ans;
int main(){
	while(cin>>n){
		ans=1;
		for(int i=1;i<=n;i++){
			ans*=3;
		}
		cout<<ans-1<<endl;
		cout<<fixed<<setprecision(0)<<(long double)(pow(3,n))-1<<endl;
	}
	return 0;
}
