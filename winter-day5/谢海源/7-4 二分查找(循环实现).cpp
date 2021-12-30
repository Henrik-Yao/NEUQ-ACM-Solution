#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6;
const int INF = 1e6;
int a[maxn],sum=0;
int find(int n,int x)//循环二分查找
{
	int l=0,r=n-1;
	sum=0;//查找次数
	while(l<=r)
	{
		sum++;
		int mid=(l+r)>>1;
		if(a[mid]>x)	r=mid-1;
		else if(a[mid]<x)	l=mid+1;
		else return mid;//返回下标
	}
	return -1;
}
int main()
{
	int n,x;
	cin>>n;
	for(int i=0;i<n;i++) cin>>a[i];
	sort(a,a+n);
	cin>>x;
	cout<<find(n,x)<<endl;
	cout<<sum;
	return 0;
}