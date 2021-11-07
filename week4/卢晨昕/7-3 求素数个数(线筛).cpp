//œﬂ–‘…∏∑® 
#include<bits/stdc++.h>
#define ll long long
#define inf 0x7fffffff
using namespace std;
int n;
int ans;
int prime[10000005];
int v[10000005];

void primes(int a)
{
	for(int i=2;i<=a;i++)
	{
		if(v[i]==0)
		{
			prime[++ans]=i;
			v[i]=i;
		}
		for(int j=1;j<=ans;j++)
		{
			if(prime[j]>v[i]||prime[j]>a/i)break;
			v[i*prime[j]]=prime[j];
		}
    }
}
int main()
{
	cin>>n;
	primes(n);
	cout<<ans;
	return 0;
}
