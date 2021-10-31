#include <bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
long long a[maxn];
long long temp[maxn];
long long sum;
void Merge(int l,int r,int m){
	int i=l;
	int j=m+1;
	int k=l;
	while(i<=m&&j<=r){
		if(a[i]>a[j]){
			sum+=m-i+1;
			temp[k++]=a[j++];
		}
		else{
			temp[k++]=a[i++];
		}
	}
	while(i<=m) temp[k++]=a[i++];
	while(j<=r) temp[k++]=a[j++];
	for(int i=l;i<=r;i++){
		a[i]=temp[i];
	}
}
void mergesort(int l,int r){
	if(l<r){
		int mid=(l+r)/2;
		mergesort(l,mid);
		mergesort(mid+1,r);
		Merge(l,r,mid);
	}
}
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sum=0;
	mergesort(1,n);
	cout<<sum;
	
	
	return 0;
}
