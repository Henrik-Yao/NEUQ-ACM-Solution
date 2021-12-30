#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6;
const int INF = 1e6;
int a[maxn],b[maxn],sum=0;
int find(int n,int x)//循环二分查找
{
	int l=1,r=n;
	sum=0;//查找次数
	while(l<=r)
	{
		sum++;
		int mid=(l+r)>>1;
		if(a[mid]>x)	r=mid-1;
		else if(a[mid]<x)	l=mid+1;
		else return mid;//返回下标
	}
	return 0;
}
int main()
{
	int n,m,x;
	while(cin>>n)
	{
		for(int i=1;i<=n;i++) cin>>a[i];
		sort(a+1,a+1+n);//排序
		cin>>m;
		for(int i=1;i<=m;i++) cin>>b[i];
		for(int i=1;i<=m;i++)
		{
			b[i]=find(n,b[i]);
		}
		for(int i=1;i<n;i++) cout<<a[i]<<" ";
		cout<<a[n]<<endl;
		for(int i=1;i<m;i++) cout<<b[i]<<" ";
		cout<<b[m]<<endl;	
	}
	return 0;
}