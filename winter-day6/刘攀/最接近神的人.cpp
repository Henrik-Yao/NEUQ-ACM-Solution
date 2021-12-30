#include<bits/stdc++.h>
using namespace std;
int ans=0;
int a[100000];
int c[100000];
void f(int l,int r){
	if(l==r) return;
	int mid=(l+r)/2;
	f(l,mid);
	f(mid+1,r);
	int k=0;int i=l;int j=mid+1;
	while(i<=mid&&j<=r){
		if(a[i]<=a[j]) c[k++]=a[i++];
		else {
			ans+=mid-i+1;
			c[k++]=a[j++];
		}
	}
	while(i<=mid) c[k++]=a[i++];
	while(j<=r) c[k++]=a[j++];
	for(int i=l,k=0;i<=r;i++,k++) a[i]=c[k];
}
int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	f(0,n-1);
	cout<<ans;
}
