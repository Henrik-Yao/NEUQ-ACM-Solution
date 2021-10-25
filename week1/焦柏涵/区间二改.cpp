#include <iostream>
#include <cstring>
using namespace std;
int a[1000001],pre[1000001],suf[1000001];
bool in[1000001];
int main()
{
	int n,i,x=0;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(i=1;i<=n;i++)
	{
		pre[i]=pre[i-1]+(!in[a[i]]);
		in[a[i]]=1;
	}
	memset(in,0,sizeof(in));
	for(i=n;i>=1;i--)
	{
		suf[i]=suf[i+1]+(!in[a[i]]);
		in[a[i]]=1;
	}
	for(i=1;i<=n;i++)
	{
		x=max(x,pre[i]+suf[i+1]);
	}
	cout<<x;
	return 0;
}
