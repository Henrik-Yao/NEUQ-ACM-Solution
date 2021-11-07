#include<bits/stdc++.h>
#define ll long long
#define inf 0x7fffffff
using namespace std;
int n;
int a[100005];
ll f[45];
int main()
{
	cin>>n;
	f[1]=0;
	f[2]=1;
	f[3]=2;
	for(int i=4;i<=40;i++)
	{
		f[i]=f[i-1]+f[i-2];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<n;i++)
	{
		cout<<f[a[i]]<<endl;
	}
	cout<<f[a[n]];
	return 0;
}
