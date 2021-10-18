#include<bits/stdc++.h>
#include<cmath>
#define R register
#define ll long long
using namespace std;
inline int read()
{
	char ch=getchar();
	int f=1,x=0;
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')f=-1;ch=getchar(); 
	}
	while(ch>='0'&&ch<='9')
	{
		x=x*10+(ch^48),ch=getchar();
	}
	return x*f;

}
int n,m,k;
struct ax{
	int x;
	int y;
}a[11000];
bool vis[11000];
int main()
{
	n=read(),m=read();
	for(int i=1;i<=m;i++)
	{
		a[i].x=read();
		a[i].y=read();
	}
	k=read();
	while(k--)
	{
		int ks=0;
		memset(vis,1,sizeof(vis));
		R int z;
		z=read();
		for(int i=1;i<=z;i++)
		{
			R int s;
			s=read();
			vis[s]=0;
		}
		for(int i=1;i<=m;i++)
		{
			if(vis[a[i].x] && vis[a[i].y])
			{
				ks=1;
				break;
			}
		}
		if(ks==1)cout<<"NO";
		else cout<<"YES";
		if(k!=0)cout<<"\n";
	}
	return 0;
}
