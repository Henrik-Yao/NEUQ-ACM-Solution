#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,m,a[1001],b[1001];
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n);
	int sum=a[n-1]-a[0]+1;
	for(int i=0;i<n-1;i++)
	{
		b[i]=a[i+1]-1-a[i];
	}
	sort(b,b+n-1);
	for(int i=1;i<=m;i++) sum-=b[n-i];
	cout<<sum;
}
