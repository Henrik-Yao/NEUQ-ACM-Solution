#include<bits/stdc++.h>
using namespace std;
bool f(int m);
int main(){
	int n,i;
	cin>>n;
	for(i=0;i<n;i++){
		long long a;
		cin>>a;
		if(a%2==0){
			cout<<'2'<<endl;
			continue;
		}
		if(f(a)){
			cout<<'1'<<endl;
			continue;
		}
		if(f(a-2)){
			cout<<'2'<<endl;
			continue;
		}
		else cout<<'3'<<endl;
	}
	return 0;
}
bool f(int m){
	for(int j=3;j*j<=m;j++){
		if(m%j==0){
			return false;
		}
	}return true;
}
