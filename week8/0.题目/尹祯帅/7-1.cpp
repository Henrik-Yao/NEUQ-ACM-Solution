#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n][2];
		for(int i=0;i<n;i++) cin>>a[i][0]>>a[i][1];
		for(int i=0;i<n;i++)
		for(int j=i;j<n;j++) 
		if(a[i][1]>a[j][1]) swap(a[i],a[j]);
		int j=0,count=1;
		for(int i=1;i<n;i++)
		if(a[j][1]<=a[i][0])
		{
			count++;
			j=i;
		}
		cout<<n-count<<'\n';
	}
	return 0;
} 
