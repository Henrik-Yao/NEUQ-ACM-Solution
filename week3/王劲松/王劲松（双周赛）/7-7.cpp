#include<bits/stdc++.h>
using namespace std;
long long cnt=0;
int n;
int p[1000000];
void merge_sort(int a[],int l,int r);
void merge(int a[],int mid,int l,int r);
int main(){
	int i;
	cin>>n;
	int a[n];
	for(i=0;i<n;i++){
		cin>>a[i];
	}
	merge_sort(a,1,n);
	cout<<cnt;
	return 0;
}
void merge_sort(int a[],int l,int r){
	int mid =l+(r-l)/2;
	if(l>=r)return;
	merge_sort(a,l,mid);
	merge_sort(a,mid+1,r);
	merge(a,mid,l,r);
}
void merge(int a[],int mid,int l,int r){
	int j,k,s=0;
	//int *p=new int[r-l+1]; 
	for(j=l,k=mid+1;j<=mid&&k<=r;){
		if(a[j-1]>a[k-1]){
			p[s++]=a[k-1];
			cnt+=mid-j+1;
			k++;
		}else
		{
			p[s++]=a[j-1];
			j++;
		}
	}
	while(j<=mid){
		p[s++]=a[j-1];
		j++;
	}
	while(k<=r){
		p[s++]=a[k-1];
		k++;
	}
	for(j=l,s=0;j<=r;s++,j++){
		a[j-1]=p[s];
	}
}
