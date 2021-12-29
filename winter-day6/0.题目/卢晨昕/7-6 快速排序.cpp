#include<bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f

using namespace std;
int n;
int a[1005];
void print(int *arr)
{
	for(int i=1;i<=n;i++)cout<<arr[i]<<" ";
	cout<<endl;
}
void qsort(int *arr,int l,int r)
{
	if(l>=r)return;
	int mid=arr[l];
	int i=l,j=r;
	while(i<j)
	{
		while(arr[j]>mid&&i<j)j--;
		while(arr[i]<=mid&&i<j)i++;
		swap(arr[i],arr[j]);
	}
	swap(arr[l],arr[i]);
	print(arr);
	qsort(arr,l,i-1);
	qsort(arr,i+1,r);
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	qsort(a,1,n);
	for(int i=1;i<=n;i++)cout<<a[i]<<" ";
	return 0;
}

