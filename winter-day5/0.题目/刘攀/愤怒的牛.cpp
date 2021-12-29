#include<bits/stdc++.h>
using namespace std;
int a[100005];
int n,m;
int check(int d){
	int sum=1;
	int p=d+a[0];
	for(int i=1;i<n;i++){
		if(a[i]<p) continue;
		p=a[i]+d;
		sum++;
	}
	if(sum>=m) return 1;
	else return 0;
}
int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	int l=0;
	int r=a[n-1]-a[0];
	while(l<=r){
		int mid=(l+r)/2;
		if(check(mid)) l=mid+1;
		else r=mid-1;
	}
	cout<<r<<endl;
}
