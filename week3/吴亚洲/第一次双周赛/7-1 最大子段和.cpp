#include<bits/stdc++.h>
using namespace std;
int n;
int a[10001],s[10001];
int main()
{
	int max1=-0x7ffffff;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		s[i]=s[i-1]+a[i];
	}
	for(int i=1;i<=n;i++)
	for(int j=i;j<=n;j++)
	{
		int sum=s[j]-s[i];
		max1=max(sum,max1); 
	}
	cout<<max1;
}
