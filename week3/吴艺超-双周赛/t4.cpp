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
double d[65],f[65];
int n;
int main()
{
	d[1]=1;
	for(int i=2;i<=64;i++)
	d[i]=2*d[i-1]+1,f[i]=1000000;
	f[1]=1;
	for(int i=2;i<=64;i++)
		for(int j=1;j<i;j++)
		f[i]=min(f[i],2*f[j]+d[i-j]);
//		f[64]=18433;
	while(cin>>n)
	{
		cout<<f[n]<<endl;
	}
	return 0;
}
