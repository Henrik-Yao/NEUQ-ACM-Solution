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
double r,d,n;
double x1,x2,x3;
int main()
{
	r=read(),d=read(),n=read();
	d=abs(d),n=abs(n);
	x1=sqrt(d*d+(n-r)*(n-r));
	if(n-r<=0) printf("%.2f",2*d-r);
else printf("%.2f",x1*2-r);
	return 0;
}
