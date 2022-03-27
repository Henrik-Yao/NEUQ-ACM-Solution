#include<bits/stdc++.h>
using namespace std;
#define ll long long
bool a[10000001]={};
int f(int n)
{
    int s=0;
	for(ll i=2;i*i<=n;i++)
	{
		if(a[i]==0)
		{
			for(ll j=i*i;j<=n;j=j+i)
			{
				a[j]=1;//标记为合数
			}
		}
	}
	for(ll i=2;i<=n;i++)
	{
		if(a[i]==0)s++;
	}
	return s;
}
int main()
{
	memset(a,0,sizeof(a));
	int n;
	cin>>n;
	cout<<f(n);
	return 0;
}