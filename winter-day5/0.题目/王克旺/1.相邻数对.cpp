#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,a[1000],count=0;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n);
	for(int i=0;i<n-1;i++)
	{
		if(a[i+1]-a[i]==1)
		{
			count++;
		}
	}
	cout<<count<<endl;
	return 0;	
}
