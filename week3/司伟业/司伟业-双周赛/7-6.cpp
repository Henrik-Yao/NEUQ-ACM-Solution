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

char c[10];
int a[50],b[50],num,vis[50];

void dfs(int x)
{
	if(x==num+1)
	{
		printf("%s\n",c+1);
		return;
	}
	for(int i=1;i<=num;i++)
	{
		if(vis[i]) continue;
		vis[i]=1;c[x]=b[i]+'a'-1;
		dfs(x+1);
		vis[i]=0;
	}
}

int main()
{
	cin>>(c+1);
	int l=strlen(c+1);
	for(int i=1;i<=l;i++)
	{
		a[c[i]-'a'+1]=1;
	}
	for(int i=1;i<=26;i++)
	{
		if(a[i]) b[++num]=i;
	}
	dfs(1);
}

