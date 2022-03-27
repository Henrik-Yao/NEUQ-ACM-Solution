#include<bits/stdc++.h>
using namespace std;
int a,b,c;
int  f(int a,int b,int c){
	long long ans=1;
	long long base=a%c;
	while(b!=0){
	if(b&1){
		ans=ans*base%c;
	}
		base=base*base%c;
		b/=2;
	}
	return ans%c;
}
int main(){
	int t;
	cin>>t;
	while(t--){
	cin>>a>>b>>c;
	int sum=f(a,b,c);
	cout<<sum<<endl;
	}
}
