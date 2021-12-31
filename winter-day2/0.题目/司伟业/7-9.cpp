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
int n,ct;
int pre[maxn],in[maxn],last[maxn],de[105][105],cnt[105],ans;

int ask(int len,int pre,int in[])
{
	for(int i=0;i<len;i++)
	{
		if(in[i]==pre)
		return i;
	}
	return -1;
}

void cal(int len,int pre[],int in[],int deep)
{
	int root=ask(len,pre[0],in);
	if(root==-1) return;
	cnt[deep]++;ans=max(ans,deep);
	de[deep][cnt[deep]]=pre[0];
	cal(root,pre+1,in,deep+1);
	cal(len-root-1,pre+root+1,in+root+1,deep+1);
}

signed main()
{
	n=read();
	for(int i=0;i<n;i++) pre[i]=read();
	for(int i=0;i<n;i++) in[i]=read();
	cal(n,pre,in,1);
	for(int i=1;i<=ans;i++)
	{
		for(int j=1;j<=cnt[i];j++)
		cout<<de[i][j]<<" ";
	}
	return 0;
}
