#include<bits/stdc++.h>
using namespace std;
void mergesort(int arr[],int l,int mid,int r)
{
	int t[r-l+1];
	int li=l,ri=mid+1;
	int i=0;
	while(li<=mid&&ri<=r)
	{
		t[i++]=arr[li]<arr[ri]?arr[li++]:arr[ri++];
	}
	while(li<=mid)
	{
		t[i++]=arr[li++];
	}
	while(ri<=r)
	{
		t[i++]=arr[ri++];
	}
	for(int j=0;j<r-l+1;j++)
	{
		arr[l+j]=t[j];
	}
}
void merge(int arr[],int l,int r)
{
	if(l==r){return;}
	else
	{
		int mid=(l+r)>>1;
		merge(arr,l,mid);
		merge(arr,mid+1,r);
		mergesort(arr,l,mid,r);
	}
}
int main()
{
	int T,m,n,a[220];
	cin>>T;
	for(int i=0;i<T;i++)
	{
		cin>>m;
		for(int j=0;j<m;j++)
		{
			cin>>a[j];
		}
		cin>>n;
		for(int j=m;j<m+n;j++)
		{
			cin>>a[j];
		}
		merge(a,0,m+n-1);
		for(int j=0;j<m+n-1;j++)
		{
			cout<<a[j]<<" ";
		}
        cout<<a[m+n-1]<<endl;
	}
	return 0;

}
