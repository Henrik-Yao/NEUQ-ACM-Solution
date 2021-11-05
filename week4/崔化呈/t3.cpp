#include<bits/stdc++.h>
#define MAX 10000010
using namespace std;
int prime[MAX],he[MAX],n,all=0;
int main()
{
	cin>>n;
	for(int i=2;i<=n;i++)
	{
		if(!he[i])
		{
			prime[++all]=i;
		}
		for(int j=1;prime[j]*i<=n&&j<=all;j++)
		{
			he[prime[j]*i]=1;
			if(i%prime[j]==0)
			{
				break;
			}
		}
	}
	cout<<all<<endl;
	return 0;
}
