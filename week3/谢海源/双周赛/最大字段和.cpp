#include<bits/stdc++.h>
using namespace std;
int maxt(int a,int b,int c)
{
	int t;
	if(a<b) t=b;
	else t=a;
	if(t<c) t=c;
	return t;
}
int maxsum(int a[],int l,int r)
{
	int sum=0,msum=0,lsum=0,rsum=0;//m——mid，l——left，r——right
	int m;
	if(l==r) sum=a[l];
	else
	{
		int mid=(l+r)/2;
		lsum=maxsum(a,l,mid);
		rsum=maxsum(a,mid+1,r);
		int s1=0,s2=0,ls=0,rs=0;
		for(int i=mid;i>=l;i--)
		{
			ls=ls+a[i];
			if(ls>s1) s1=ls;
	    }
		for(int i=mid+1;i<=r;i++)
		{
		    rs=rs+a[i];
			if(rs>s2) s2=rs;
		}
		msum=s1+s2;
		sum=maxt(msum,lsum,rsum);
	}
	return sum;
}
int main()
{
	int n;
	cin>>n;
	int a[n+1];
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];//输入
	}
	cout<<maxsum(a,1,n);
	return 0;
}