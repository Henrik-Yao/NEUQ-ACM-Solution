#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m;
	long long a[41];
	cin>>n;
	a[1]=0;a[2]=1;a[3]=2;
	for(int i=4;i<=40;i++){
		a[i]=a[i-1]+a[i-2];
	}
	for(int i=0;i<n;i++){
		cin>>m;
		cout<<a[m]<<endl;
	}
	return 0;
}
