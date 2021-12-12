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

struct node
{
	int l,r;
}a[maxn];
int t,n,ans;
bool cmp(node a,node b)
{
	if(a.l==b.l) return a.r<b.r;
	else return a.l<b.l;
}

int main()
{
	t=read();
	while(t--)
	{
		n=read();ans=0;
		for(int i=1;i<=n;i++)
		{
			a[i].l=read();
			a[i].r=read();
		}
		sort(a+1,a+1+n,cmp);
		int last=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i].l>=last) last=a[i].r;
			else
			{
				last=min(last,a[i].r);
				ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
