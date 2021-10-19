#include<bits/stdc++.h>
using namespace std;
int n;
int a[1005];

int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)a[i]=1;
	for(int i=2;i<=n;i++)
	{
		for(int j=1;j<i;j++)
		{
			if(i%j==0)
			{
				a[i]+=a[j];
			}
		}
	}
	cout<<a[n];
	return 0;
}
