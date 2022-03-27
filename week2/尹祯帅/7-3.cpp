#include<bits/stdc++.h>
using namespace std;
int n;
int js(int r[],int s[],int b,int m,int e)
{
	int i=b,j=m+1,k=b;
	while(i<=m&&j<=e)
	{
		if(r[i]<r[j])
		{
			s[k]=r[i];
			i++;
			k++;
		}
		else
		{
			s[k]=r[j];
			j++;
			k++;
		}
	}
	while(j<=e)
	{
		s[k]=r[j];
		j++;
		k++;
	}
	while(i<=m)
	{
		s[k]=r[i];
		i++;
		k++;
	}
	return 0;
}
int gb(int r[],int s[],int begin,int end)
{
	int mid=(begin+end)/2;
	int t[n];
	for(int i=begin;i<=end;i++) t[i]=r[i];
	if(begin==end) s[end]=r[end];
	else
	{
		gb(r,t,begin,mid);
		gb(r,t,mid+1,end);
		js(t,s,begin,mid,end);
	}
	return 0;
}
int main()
{
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	gb(a,a,0,n-1);
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<' ';
	}
	return 0;
	
}