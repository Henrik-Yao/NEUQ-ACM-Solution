#include<bits/stdc++.h>
using namespace std;
const int M=1000001;
int a[M];
int t[M];
void findsort(int arr[],int l,int mid,int r);//跟分治递归原理一样 
void find(int arr[],int l,int r);
long long ans=0,n;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	find(a,1,n);
	cout<<ans;
	return 0;	
}
void findsort(int arr[],int l,int middle,int r)
{
	int i=l,li=l,ri=middle+1;
	while(li<=middle&&ri<=r)
	{
		if(arr[li]<=arr[ri])
		{
			t[i++]=arr[li++];
		}
		else
		{
			t[i++]=arr[ri++];
			ans+=middle-li+1;
		}	
	}
	while(li<=middle)
	{
		t[i++]=arr[li++];
	}
	while(ri<=r)
	{
		t[i++]=arr[ri++];
	}
	for(int j=l;j<=r;j++)
	{
		arr[j]=t[j];
	}
}
void find(int arr[],int l,int r)
{
	if(l==r)
	{
		return;
	}
	int middle=(l+r)/2;
	find(arr,l,middle);
	find(arr,middle+1,r);
	findsort(arr,l,middle,r);
}
