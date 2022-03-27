#include<bits/stdc++.h>
using namespace std;
int flag=0,n,m,mid,l,r,a[1000010],cun;
void find(int l,int r,int mid){
	if(l+1==r){
		if(a[l]>=m)cun=l;
		else if(a[r]>=m)cun=r;
		cout<<cun;
		return;
	}
	if(a[mid]>=m){
		int x=(l+mid)/2;
		cun=mid;
		find(l,mid,x);
	}
	else if(a[mid]<m){
		int x=(mid+r)/2;
		find(mid,r,x);
	}
}
int main(){
	cin>>n>>m;
	cun=n+1;
	for(int i=1;i<=n;i++){
		scanf("%d",a+i);
	}
	l=1;
	r=n;
	mid=(l+r-1)/2;
	find(l,r,mid);
	return 0;
}
