#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
#define int long long
#define maxn 1000005
using namespace std;

int read()
{
	int x=1,res=0;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')
		x=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		res=res*10+(c-'0');
		c=getchar();
	}
	return res*x;
}

int a[maxn],c,cnt;

signed main()
{
	while(cin>>c)
	{
		a[++cnt]=c;
	}
	sort(a+1,a+1+cnt);
	for(int i=1;i<=cnt;i++)
	{
		if(i==1) printf("%lld",a[i]);
		else printf("->%lld",a[i]); 
	}
	puts("");
	int flag=0;
	for(int i=1;i<=cnt;i++)
	{
		if(a[i]%2==0) continue;
		if(flag==0)
		{
			flag=1;
			printf("%lld",a[i]);
		}
		else printf("->%lld",a[i]); 
	}flag=0;puts("");
	for(int i=1;i<=cnt;i++)
	{
		if(a[i]%2==1) continue;
		if(flag==0)
		{
			flag=1;
			printf("%lld",a[i]);
		}
		else printf("->%lld",a[i]); 
	}
	return 0;
}
