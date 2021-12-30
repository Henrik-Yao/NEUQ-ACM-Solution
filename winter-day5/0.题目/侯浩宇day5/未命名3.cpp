#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,a[200001],b[200001],m=0;
	cin>>n;
	for(int i=0;i<n;i++)
	cin>>a[i];
	for(int i=0;i<n;i++)
	cin>>a[n+i];
	sort(a,a+2*n);

	cout<<a[n-1];
	return 0;
}
