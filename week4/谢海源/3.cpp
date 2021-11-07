#include<bits/stdc++.h>
using namespace std;
bool a[10000001];//值为0的为质数
int s[10000001];
int f(int n)
{
	for(int i=2;i<=n;i++)
	{
		if(a[i]==0) s[n]++;
	}
	return s[n];
}
int main()
{
	memset(a,0,sizeof(a));
	memset(s,0,sizeof(s));
	a[1]=1;//非质数
	int n;
	scanf("%d",&n);
	for(int i=2;i*i<=n;i++)
	{
		if(a[i]==0)
		{
			for(int j=i*i;j<=n;j=j+i)
			{
				a[j]=1;//标记为非素数
			}
		}
	}
	cout<<f(n)<<endl;
	return 0;
}
