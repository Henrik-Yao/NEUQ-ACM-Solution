#include<bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f
using namespace std;
int n,c;
int w[405],v[405];
int f[1505];
int maxn;
int main()
{
	while(scanf("%d",&n)!=EOF)
	{
		cin>>c;
		memset(f,0,sizeof(f));
		maxn=0;
		for(int i=1;i<=n;i++)cin>>w[i];
		for(int i=1;i<=n;i++)cin>>v[i];
		for(int i=1;i<=n;i++)
		{
			for(int j=c;j>=w[i];j--)
			{
				if(f[j-w[i]]+v[i]>f[j])f[j]=f[j-w[i]]+v[i];
			}
		}
		for(int i=0;i<=c;i++)if(f[i]>maxn)maxn=f[i];
		cout<<maxn<<endl;
	}
	return 0;
}
