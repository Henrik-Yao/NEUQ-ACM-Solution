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
bool isprime[N+1];
int prime[N+1],cnt;
int tot,n;
void oula()
{
	for(int i=2;i<=n;i++)
	{
		if(!isprime[i])prime[++cnt]=i,tot++;
		for(int j=1;i*prime[j]<=n && j<=cnt;j++)
		{
			isprime[i*prime[j]]=1;
			if(i%prime[j]==0)
			break;
		}
	}
}
int main()
{
	cin>>n;
	oula();
	cout<<tot;
	return 0;
}
