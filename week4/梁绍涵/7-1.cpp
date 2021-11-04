#include<bits/stdc++.h>
using namespace std;
int vis[100000],is_prime[100000];
bool prime(int x)
{
	for(int i=2;i<=sqrt(x);i++)
	{
		if(x%i==0)
		return 0;
	}
	return 1;
}
int main()
{
	int a,b;
	memset(is_prime,-1,sizeof(is_prime));
	is_prime[1]=0;
	is_prime[2]=1;
	while(cin>>a>>b)
	{
		for(int i=3;i<=b;i++)
		{
			if(!prime(i))
			{
				for(int j=i+i;j<=b;j+=i)
				{
					is_prime[j]=0;
				}
			}
			else
			is_prime[i]=1;
		}
		int flag=1;
		for(int i=a;i<=b;i++)
		{
			if(is_prime[i]==1&&flag==1)
			{
				cout<<i;
				flag=0;
				continue;
			}
			if(is_prime[i]==1&&flag==0)
			cout<<" "<<i;
		}
		
		cout<<endl;
	}
}
