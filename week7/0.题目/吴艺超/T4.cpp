#include<bits/stdc++.h>
using namespace std;
int t,n;
int a[100005];
int f[100005];
int ans[100005],tot;
int main()
{
	cin>>t;
	for(int j=1;j<=t;j++)
	{
		int maxx=0;
		cin>>n;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		for(int i=1;i<=n;i++)
		{
			f[i]=1;
			for(int j=1;j<i;j++)
			{
				if(a[j]<a[i])
				{
					f[i]=max(f[i],f[j]+1);
					maxx=max(maxx,f[i]);
				}
			}
		}
		cout<<maxx<<endl;
		if(j!=t)cout<<endl;
	}
	return 0;
}
