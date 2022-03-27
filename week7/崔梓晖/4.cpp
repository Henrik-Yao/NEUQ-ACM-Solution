#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,a[1010],f[1010],ans=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			f[i]=1;
		}
		for(int i=2;i<=n;i++)
		{
			for(int j=1;j<=i;j++)
			{
				if(a[j]<a[i])
				{
					f[i]=max(f[i],f[j]+1);
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
			ans=max(ans,f[i]);
		}
		cout<<ans;
		if(t!=0)
		cout<<endl<<endl;
	}
	return 0;
}
