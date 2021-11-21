#include<bits/stdc++.h>
using namespace std;
bool jud(int n){
	for(int i=2;i<=sqrt(n);i++)
		if(n%i==0) return false;
	return true;
}
int main(){
	int n,t;
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>t;
		if(t%2==0)
			cout<<2<<endl;
		else if(jud(t))
			cout<<1<<endl;
		else if(jud(t-2))
				cout<<2<<endl;
		else cout<<3<<endl;
	}
	return 0;
}
