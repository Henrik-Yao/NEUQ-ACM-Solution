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
int m,n,tot=1;
struct ax{
	string ming;
	int chao;
}a[200000];
int main()
{
	n=read(),m=read();
	for(int i=1;i<=n;i++)
		cin>>a[i].chao>>a[i].ming;
	while(m--)
	{
		int hao,x;
		hao=read(),x=read();
		if(a[tot].chao==0)
		{
			if(hao==0)tot-=x;
			if(hao==1)tot+=x;
			while(tot<0)
				tot+=n;
			while(tot>n)
				tot-=n;
		}
		else
		{
			if(hao==0)tot+=x;
			if(hao==1)tot-=x;
			while(tot<=0)
				tot+=n;
			while(tot>n)
				tot-=n;
		}
	}
		cout<<a[tot].ming;
	return 0;
}
