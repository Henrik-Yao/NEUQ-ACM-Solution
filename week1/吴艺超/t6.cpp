#include<bits/stdc++.h>
#include<cmath>
#define R register
#define N 999
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
int n,t,T,v;
int maxx=-2147483647;
int main()
{
	n=read(),T=read();
	for(int i=1;i<=n;i++)
	{
		v=read(),t=read();
		if(t<T)maxx=max(maxx,v);
		else maxx=max(maxx,v-(t-T));
	}
	cout<<maxx;
	return 0;
}
