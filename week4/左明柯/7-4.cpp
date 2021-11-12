#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll fastpower(ll base,ll power,ll c){
	ll result=1;
	while(power>0){
		if(power%2==0) {
		base=base*base%c;
		power/=2;}
		if(power%2==1){
			power=power-1;
			result=result*base%c;
			
		}
	}
	return result%c;
}
int main(){

int T;int a,b,c;
cin>>T;
while(T--){
	cin>>a>>b>>c;
	cout<<fastpower(a,b,c)<<endl;
}
