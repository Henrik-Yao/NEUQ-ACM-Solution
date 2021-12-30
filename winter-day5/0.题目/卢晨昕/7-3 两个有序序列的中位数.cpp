#include<bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f

using namespace std;
int n;
int a[200005];
int main()
{
	int i=0;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(;i<2*n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+2*n);
	cout<<a[(2*n-1)/2];
	return 0;
}

