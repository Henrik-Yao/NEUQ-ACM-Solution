#include<bits/stdc++.h>
using namespace std;
int a[1000001];
int main()
{
	int n,m,f=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]>=m&&f==0) 
		{
			f=i;
		}
	}
	if(f==0)
	cout<<n+1;
	else
	cout<<f;
}

