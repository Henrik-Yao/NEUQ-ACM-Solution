#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,a[100001],b[100001];
	cin>>n;
	for(int i=0;i<n;i++)
	cin>>a[i];
	sort(a,a+n);
	for(int i=0;i<n;i++)
	b[i]=0;
	for(int i=0;i<n;i++){
		b[a[i]]++;
	}
	for(int i=0;i<n;i++)
	if(a[i]!=a[i-1])cout<<a[i]<<":"<<b[a[i]]<<endl;
	return 0;
}
