#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;

int read()
{
	int res=0,x=1;
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

long long aa,ans;

int main()
{
	while(~scanf("%d",&aa))
	{
		ans=0;
		for(int i=1;i<=aa;i++)
		{
			ans=ans*3+2;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
