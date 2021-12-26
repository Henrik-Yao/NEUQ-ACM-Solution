#include<iostream>
#include<cstdio>
#include<string>
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

int t,c[maxn],fail[maxn],ans;

int rd(int deep)
{
	int l,r,val,j;
	val=read();
	if(val==0) return 0;
	c[deep]=val;
	j=fail[deep-1];
	while(j!=0&&c[j+1]!=val)
	j=fail[j];
	if(c[j+1]==val&&deep!=1) j++;
	fail[deep]=j;
	l=rd(deep+1);r=rd(deep+1);
	if(l==0&&r==0)
		ans=max(ans,fail[deep]-1);
	return 1;
}

signed main()
{
	t=read();
	while(t--)
	{
		ans=-1;
		rd(1);
		printf("%d\n",ans);
	}
	return 0;
}
