#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,a[55],x;
	memset(a,0,sizeof(a));
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>x;
		a[x]++;
	}
	for(int i=0;i<=50;i++)
	{
		if(a[i]!=0)
		{
			cout<<i<<":"<<a[i]<<endl;
		}
	}
	return 0;
}
