#include<bits/stdc++.h>
using namespace std;
int a[55],n;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int x;
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
