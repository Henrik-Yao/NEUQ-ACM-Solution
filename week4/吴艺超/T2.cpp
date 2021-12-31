#include<bits/stdc++.h>
#define ll long long
#define N 10000000
using namespace std;
inline int read()
{
	char ch=getchar();
	int x=0,f=1;
	while(ch<'0' || ch>'9')
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0' && ch<='9')
	{
		x=x*10+(ch^48);
		ch=getchar();
	}
	return x*f;
}
int n;
int a[41];
int main()
{
	a[1]=0,a[2]=1,a[3]=2;
	for(int i=4;i<=40;i++)
	a[i]=a[i-1]+a[i-2];
	cin>>n;
	while(n--)
	{
		int x;
		x=read();
		cout<<a[x]<<endl;
	}
	return 0;
}
