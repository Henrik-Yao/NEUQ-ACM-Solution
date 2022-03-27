#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#define maxn 1000005
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

int n,a[maxn],vis[maxn];
int main()
{
//	freopen("111.out","r",stdin);
	n=read();int cnt=0;
	for(int i=1;i<=n;i++){
		a[i]=read();a[i]+=i;
	}
	int m=1,k;
	for(int i=m;i<n;i=k)
	{
		cnt++;if(a[i]>=n) break;
		for(int j=i+1;j<=a[i];j++)
		{
			if(a[j]>m)
			{
				m=a[j];
				k=j;
			}
		}
	}
	cout<<cnt;
	return 0;
}
