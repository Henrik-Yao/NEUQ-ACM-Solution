#include<bits/stdc++.h>
#define ll long long
#define N 10000
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
int a,b;
int vis[11000];
void prime()
{
	vis[0]=vis[1]=1;
	for(int i=2;i<=N;i++)
	{
		if(!vis[i])
		{
			for(int j=i*i;j<=N;j+=i)
				vis[j]=1;
		}
	}
}
int flag;
int main()
{
	prime();
	while(cin>>a>>b)
	{
		flag=1;
		for(int i=a;i<=b;i++)
			{
				if(!vis[i] && flag)
				{
					flag=0;
					cout<<i;
					continue;
				}
				if(!vis[i] && !flag)
				cout<<" "<<i;
			}
		cout<<endl;
	}
	return 0;
}
