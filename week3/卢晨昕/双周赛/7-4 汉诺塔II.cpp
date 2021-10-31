#include<bits/stdc++.h>
#define ll long long
#define inf 0x7fffffff
using namespace std;
int n;
unsigned long long d[105];
unsigned long long f[105];
int main()
{
	while(cin>>n)
	{
		memset(f,0x7fffffff,sizeof(f));
		d[1]=1;
		for(int i=2;i<=n;i++)
		{
			d[i]=2*d[i-1]+1;
		}
		f[1]=1;
		for(int i=2;i<=n;i++)
		{
			for(int j=1;j<i;j++)
			{
				f[i]=min(f[i],2*f[j]+d[i-j]);
			}
		}
		cout<<f[n]<<endl;
	}
	return 0;
}
