#include<bits/stdc++.h>
using namespace std;
int a[100010];
int sum=0,n;
int main()
{
	cin>>n;
	for(int i=1;i<=n*2;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n+n);
	cout<<a[n];
	
	
	
}
