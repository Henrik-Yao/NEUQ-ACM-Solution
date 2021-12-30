#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,sum=0;
	cin>>n;
	int a[20000];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n);
	for(int i=1;i<n;i++)
	{
		if(a[i]-a[i-1]==1)
		sum++;
	}
	cout<<sum;
}
