#include<bits/stdc++.h>
using namespace std;
int n,x,a[110];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x;
		a[x]++; 
	}
	for(int i=0;i<=50;i++){
		if(a[i])cout<<i<<':'<<a[i]<<endl;
	}
	return 0;
}
