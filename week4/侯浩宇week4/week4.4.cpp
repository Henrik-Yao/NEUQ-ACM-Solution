#include<bits/stdc++.h>
using namespace std;

int main(){
	long long t,a,b,c;
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>a>>b>>c;
		long long ans=1;
		for(int j=0;j<b;j++)
		ans*=a,ans%=c;
		cout<<ans<<endl;
	}
	return 0;
}
