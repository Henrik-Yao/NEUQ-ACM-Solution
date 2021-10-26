#include<bits/stdc++.h>
using namespace std;
const int M=100050;
int a[M];
void mergesort(int arr[],int l,int mid,int r)
{
	int h[r-l+1];
	int li=l,ri=mid+1;
	int i=0;
	while(li<=mid&&ri<=r)
	{
		h[i++]=arr[li]<arr[ri]?arr[li++]:arr[ri++];
	}
	while(li<=mid)
	{
		h[i++]=arr[li++];
	}
	while(ri<=r)
	{
		h[i++]=arr[ri++];
	}
	for(int j=0;j<r-l+1;j++)
	{
		arr[l+j]=h[j];
	}
	
}
void mergegui(int arr[],int l,int r)
{
	if(l==r){return;}
	int mid=(l+r)/2;
	mergegui(arr,l,mid);
	mergegui(arr,mid+1,r);
	mergesort(arr,l,mid,r);
	
	
}
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	if(n==1){cout<<a[0];return 0;}
	mergegui(a,0,n-1);
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
	
	return 0;
	
}
