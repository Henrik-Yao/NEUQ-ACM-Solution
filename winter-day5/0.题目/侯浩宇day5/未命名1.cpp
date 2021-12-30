#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,m=0,a[1001];
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for(int i=0;i<n;i++)
	for(int j=i+1;j<n;j++)
	if(a[j]-a[i]==1)m++;
	cout<<m;
	return 0;
}
