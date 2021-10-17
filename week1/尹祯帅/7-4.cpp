#include<bits/stdc++.h>
using namespace std;
int n,a[1001];
int main()
{
	
	cin>>n;
	a[1]=1;a[2]=2;
	for(int i=3;i<=n;i++)
	{
		for(int j=1;j<i;j++)
		{
			if(i%j==0)
			{
				a[i]+=a[j];
			}
		}
		a[i]++;
	}
	cout<<a[n];
	return 0;
}

