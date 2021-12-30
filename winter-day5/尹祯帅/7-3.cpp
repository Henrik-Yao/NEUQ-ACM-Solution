#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int a[n],b[n];
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=0;i<n;i++) cin>>b[i];
	int m=2*n,q=0,p=0;
	int c[m];
	for(int i=0;i<m;i++)
	{
		if(q<n&&p<n)
		{
			if(a[q]<b[p]) 	c[i]=a[q++];
			else c[i]=b[p++];
		}
		else if(q<n) c[i]=a[q++];
		else c[i]=b[p++];
	}
	cout<<c[n-1];
	return 0;
} 
