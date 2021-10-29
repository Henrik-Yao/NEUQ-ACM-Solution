#include<cstdio>
#include<iostream>
#include<cstring>
const int N = 1e6 + 10;
using namespace std;
int n,ans,a[N],pre[N],suf[N];
bool in[N];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		pre[i]= pre[i-1]+(!in[a[i]]);
		in[a[i]]=1;
	}
	memset(in,0,sizeof(in));
	for(int i=n;i;i--)
	{
		suf[i]=suf[i+1]+(!in[a[i]]);
		in[a[i]]=1;
	}
	for(int i=1;i<n;i++) 
	ans=max(ans,pre[i]+suf[i+1]);
	cout<<ans;
	return 0;
}
