#include<bits/stdc++.h>
using namespace std;
int n,c;
int w[405],v[405];
int f[405][1566];
int main()
{
	while(cin>>n)
	{
		cin>>c;
		memset(f,0,sizeof(0));
		for(int i=1;i<=n;i++)
		cin>>w[i];
		for(int i=1;i<=n;i++)
		cin>>v[i];
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=c;j++)
			{
				f[i][j]=f[i-1][j];
				if(j>=w[i])
				f[i][j]=max(f[i][j],f[i-1][j-w[i]]+v[i]);
			}
		}
		int Max=0;
		for(int i=1;i<=n;i++)
		for(int j=1;j<=c;j++)
		Max=max(f[i][j],Max);
		cout<<Max<<endl;
	}
}
