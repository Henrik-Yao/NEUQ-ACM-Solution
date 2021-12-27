#include<iostream>
#include<cstdio>
#include<string>
#include<cmath>
#include<cstring>
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

struct tr{
	int l,r,val;
}g[maxn];
int t,n,aa,tot,de,flag;

void dfs(int x,int d)
{
	if(g[g[x].l].val!=0)
	dfs(g[x].l,d+1);
	if(flag==0)
	{
		cout<<g[x].val;
		flag=1;
	}
	else cout<<" "<<g[x].val;
	if(g[g[x].r].val!=0)
	dfs(g[x].r,d+1);
}

signed main()
{
	t=read();
	while(t--)
	{
		n=read();de=0;flag=0;
		memset(g,0,sizeof(g));
		for(int i=1;i<=n;i++)
		{
			aa=read();
			if(aa!=0) de=max(de,int(log(i)/log(2)+1));
			g[i].val=aa;
			if(i==1) continue;
			if(i%2==0) g[i/2].l=i;
			else g[i/2].r=i;
		}
		dfs(1,1);
		cout<<endl;
		cout<<de<<endl;
	}
	return 0;
}
