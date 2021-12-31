#include<bits/stdc++.h>
using namespace std;
int n,a[41],m;
int main()
{
	cin>>n;
	a[1]=0;
	a[2]=1;
    a[3]=2;
	while(n--)
	{
		cin>>m;

		
			for(int i=4;i<=m;i++)
		     a[i]=a[i-1]+a[i-2];
		     cout<<a[m];
		
		if(n!=0) cout<<'\n';
	}
	return 0;
 } 

