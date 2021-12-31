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
		f[1]=2;
		for(int i=2;i<=n;i++)
		{
			f[i]=f[i-1]+1+f[i-1]+1+f[i-1];
		}
		cout<<f[n]<<endl;
	}
	return 0;
}
