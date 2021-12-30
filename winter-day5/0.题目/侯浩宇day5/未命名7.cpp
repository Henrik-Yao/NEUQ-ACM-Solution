#include<bits/stdc++.h>
using namespace std;
int n,m,a[1000001],mid;
int check(int d){
	int s=d+a[0];
	int sum=1;
	for(int i=1;i<n;i++){
		if(a[i]<s)continue;
		s=d+a[i];
		sum++;
	}
	return sum>=m;
}
int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++)
	cin>>a[i];
	sort(a,a+n);
	int l=0,r=a[n-1]-a[0];
	while(l<=r){
		mid=(r+l)>>1;
		if(check(mid)){
			l=mid+1;
		}
		else r=mid-1;
	}
	cout<<r;
	return 0;
}
