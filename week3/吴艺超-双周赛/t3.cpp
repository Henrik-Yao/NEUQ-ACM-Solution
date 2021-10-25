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
int n;
int main()
{
	while(cin>>n)
	{
		ll ans=1;
		for(int i=1;i<=n;i++)
			ans*=3;
			ans--;
		printf("%lld\n",ans);
	}
	return 0;
}

