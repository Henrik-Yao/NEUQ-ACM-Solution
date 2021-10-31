#include <bits/stdc++.h>
using namespace std;
int a[100000];
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n,less<int>());
	for(int i=0;i<n;i++)
	cout<<a[i]<<" ";
	
	return 0;
 } 
