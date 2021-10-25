#include<bits/stdc++.h>
#define ll long long
#define inf 0x7fffffff
using namespace std;
int n;
int ans=0;
int a[10005];
int f[10005];
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	f[1]=a[1];
	for(int i=2;i<=n;i++)
	{
		f[i]=max(f[i-1]+a[i],a[i]);
		ans=max(ans,f[i]);
	}
	cout<<ans;
	return 0;
}
