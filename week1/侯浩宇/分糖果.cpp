#include<bits/stdc++.h>
using namespace std;
int n,m=0;
void dg(int n){
	for(int i=1;i<=n;i++){
		if(i==n) break;
		if(n%i==0) m++,dg(i);
		
	}
}
int main(){
	
	cin>>n;
	dg(n);
	cout<<m+1;
	return 0;
}
