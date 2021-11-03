#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#define maxn 10000005
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

int n,vis[maxn],ans;

int main()
{
	n=read();
	for(int i=2;i<=n;i++)
	{
		if(vis[i]) continue;
		ans++;
		if((long long)i*i<=n)
		for(int j=i*i;j<=n;j+=i)
		{
			vis[j]=1;
		}
	}
	cout<<ans;
	return 0;
}
