#include<bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f
using namespace std;
int t,n;
int a[1005];
int f[1005];
int maxn=0;
int main()
{
	cin>>t;
	while(t--)
	{
		memset(f,0,sizeof(f));
		memset(a,0,sizeof(a));
		maxn=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		for(int i=1;i<=n;i++)
		{
			f[i]=1;
			for(int j=1;j<i;j++)
			{
				if(a[j]<a[i])
				{
					f[i]=max(f[i],f[j]+1);
				}
			}
			if(f[i]>maxn)maxn=f[i];
		}
		cout<<maxn<<endl;
		if(t)cout<<endl;
	}
	return 0;
}
