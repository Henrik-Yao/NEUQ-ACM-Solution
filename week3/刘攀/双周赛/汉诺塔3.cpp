#include<bits/stdc++.h>
using namespace std;
long long  a[100];
int main(){
	int n;
	while(cin>>n){
	a[1]=2;
	for(int i=2;i<=35;i++){
		a[i]=a[i-1]*3+2;
	}	
	cout<<a[n]<<endl;
	}
}
