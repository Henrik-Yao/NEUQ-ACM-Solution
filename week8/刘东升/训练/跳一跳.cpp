#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,ans;
const int M=2000005;
int judge[M],b[M];
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	cin>>judge[i];
	for(int i=1;i;i=b[i])
	{
		int tmp=0;
		int xmax=0;
		for(int j=1;(j<=judge[i]);j++)
		{
			if(tmp<i+j+judge[i+j])
			{
				tmp=i+j+judge[i+j];
				xmax=i+j;
			}
		}
		b[i]=xmax;ans++;
		if(tmp>=n)
		{
			ans++;
			break;
		}
	}
	cout<<ans;
	return 0;
}
