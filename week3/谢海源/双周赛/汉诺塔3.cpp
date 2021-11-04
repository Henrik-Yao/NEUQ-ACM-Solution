#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
	ll a[36]={};
	a[1]=2;
	for(int i=2;i<=35;i++)
	{
		a[i]=3*a[i-1]+2;
	}
	int n;
	while(cin>>n)
	{
		cout<<a[n]<<endl;
	}
	return 0;	
}
