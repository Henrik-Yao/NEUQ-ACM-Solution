#include<bits/stdc++.h>
using namespace std;
int a[1000001];
int f(int m,int l,int r){
	int b=r;
	while(l<r){
		int mid=(l+r)/2;
		if(a[mid]>=m) r=mid;
		else l=mid+1;
	}
	if(a[l]>=m) return l;
	return r+1;
}
int main(){
	int n;
	cin>>n;
	int m;
	cin>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	cout<<f(m,1,n);
}
