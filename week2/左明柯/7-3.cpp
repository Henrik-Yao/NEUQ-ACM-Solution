#include <iostream>
#define maxn  100000
using namespace std;
 int a[maxn];
int temp[maxn];

void merg(int l,int r,int mid){
	int i,j,p;
	i=l;j=mid;p=l;
	while(i<mid&&j<=r){
		if(a[i]<a[j])
		temp[p++]=a[i++];
		else 
		temp[p++]=a[j++];
	}
	while(i<mid){
		temp[p++]=a[i++];
	}
	while(j<=r){
		temp[p++]=a[j++];
	}
	p=l;i=l;
	while(p<=r){
		a[i++]=temp[p++];
	}
}


void merge_sort(int l,int r){
if(l<r){
	int mid=(l+r)/2;
	merge_sort(l,mid);
	merge_sort(mid+1,r);
	merg(l,r,mid+1);
}
}
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	      cin>>a[i];
	merge_sort(1,n);
	for(int i=1;i<=n;i++)
	      cout<<a[i]<<' ';
}













