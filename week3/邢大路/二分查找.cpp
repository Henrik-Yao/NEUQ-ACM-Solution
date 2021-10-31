#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m;
	cin>>n>>m;
	int a[n+1];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(a[n]<m){
		cout<<n+1;
		return 0;
	}
	int begin=1,end=n;
	while(begin<=end){
		int half=(begin+end)/2;
	if(a[half]>=m){
		end=half-1;
	}
	else{
		begin=half+1;
	}
	}
	cout<<begin;
	return 0;
}
 
