#include<bits/stdc++.h>
using namespace std;
int a[200000];
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(int i=n;i<2*n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+2*n);
	cout<<a[(2*n-1)/2]<<endl;
	return 0;
}
