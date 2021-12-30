#include<bits/stdc++.h>
using namespace std;
int a[1010];
int sum=0,n;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=0;i<n;i++)
	{
		if(a[i+1]-a[i]==1) sum++;
	}
	cout<<sum;
	
	
	
}
