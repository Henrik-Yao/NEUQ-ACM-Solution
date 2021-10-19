#include<bits/stdc++.h>
#include<cmath>
#define R register
#define N 999
#define ll long long
using namespace std;
inline int read()
{
	char ch=getchar();
	int f=1,x=0;
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')f=-1;ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=x*10+(ch^48),ch=getchar();
	}
	return x*f;
}
int n,maxx=0;
int a[1000005],b[1000005];
bool a1[100005],b1[100005];
int a2[1000005],b2[1000005];
int main()
{
	n=read();
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
		b[n+1-i]=a[i];
	}
	for(int i=1;i<=n;i++)
	{
		a2[i]=a2[i-1];
		if(a1[a[i]]==0)
		{
			a1[a[i]]=1;
			a2[i]++;
		}
		b2[i]=b2[i-1];
		if(b1[b[i]]==0)
		{
			b1[b[i]]=1;
			b2[i]++;
		}
	}
	for(int i=0;i<=n;i++)
	maxx=max(maxx,a2[i]+b2[n-i]);
	cout<<maxx;
	return 0;
}
