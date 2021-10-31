#include<bits/stdc++.h>
using namespace std;
long long a [1000001];
long  long c[1000001];
long long ans=0;
void f(long long  l,long long r){
	if(l==r) return;
	long long mid=(l+r)/2;
	f(l,mid);
	f(mid+1,r);
	long long i=l,j=mid+1,k=0;
	while(i<=mid&&j<=r){
	if(a[i]<=a[j]) c[k++]=a[i++];
	else{
	ans+=mid-i+1;
	c[k++]=a[j++];
}
	}
	while(i<=mid) c[k++]=a[i++];
	while(j<=r) c[k++]=a[j++];
	for(long long i=l,k=0;i<=r;i++,k++) a[i]=c[k];
}
int main(){
	long long  n;
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	f(1,n);
	cout<<ans;
}
