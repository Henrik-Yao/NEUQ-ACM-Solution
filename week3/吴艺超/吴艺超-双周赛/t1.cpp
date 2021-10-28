#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline int read()
{
	char ch=getchar();
	int x=0,f=1;
	while(ch<'0' || ch>'9')
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0' && ch<='9')
	{
		x=x*10+(ch^48);
		ch=getchar();
	}
	return x*f;
}
int a[11000],ans,tmp,maxx=-2147483647,n;
int main()
{
	n=read();
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
		maxx=max(maxx,a[i]);
	}
	if(maxx<=0)
	{
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		tmp+=a[i];
		if(tmp<0)tmp=0;
		ans=max(tmp,ans);
	}
	cout<<ans;
	return 0;
}
