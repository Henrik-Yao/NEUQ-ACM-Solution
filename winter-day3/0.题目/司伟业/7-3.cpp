#include<iostream>
#include<cstdio>
#include<string>
#include<map>
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

int n,a[maxn],f[maxn],ans;
map<string,int>vis;

void pd(int cnt)
{
	if(cnt==0||cnt==1) return;
	int a=1;string res="    ",t; 
	for(int i=1;i<=cnt;i++)
	{
		res[1]=f[i]/100+'0';
		res[2]=f[i]/10%10+'0';
		res[3]=f[i]%10+'0';
		t+=res;
		if(f[i]<f[i-1])
		a=0;
	}
//	cout<<t<<endl;
	if(vis[t]==0) vis[t]=1;
	else return;
	if(a==1) ans++;
}

void dfs(int x,int cnt)
{
	if(x==n+1)
	{
		pd(cnt);
		return;
	}
	dfs(x+1,cnt);
	f[cnt+1]=a[x];
	dfs(x+1,cnt+1);
}

signed main()
{
	n=read();f[0]=-2e9;
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
	}
	dfs(1,0);
	cout<<ans;
	return 0;
}
