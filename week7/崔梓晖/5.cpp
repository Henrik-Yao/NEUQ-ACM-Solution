#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	while(cin>>n)
	{
		int m,w[1001],v[1001],f[10001];
		memset(f,0,sizeof(f));
		cin>>m;
		for(int i=1;i<=n;i++)
		{
			cin>>w[i];
		}
		for(int i=1;i<=n;i++)
		{
			cin>>v[i];
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=m;j>=w[i];j--)
			{
				f[j]=max(f[j],f[j-w[i]]+v[i]);
			}
		}
		cout<<f[m]<<endl;	
	}
	return 0;
}
