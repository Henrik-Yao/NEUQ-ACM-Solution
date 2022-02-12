#include<bits/stdc++.h>
using namespace std;
int n;
int a[300001];
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=n;i<2*n;i++){
		cin>>a[i];
	}
	sort(a,a+2*n);
	cout<<a[n-1];
}
