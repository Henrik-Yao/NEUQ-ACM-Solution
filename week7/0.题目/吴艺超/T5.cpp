#include<bits/stdc++.h>
using namespace std;
int n,c;
int w[1000000],v[1000000],f[1000000];
int main()
{
	while(cin>>n>>c)
	{
		memset(f,0,sizeof(f));
		for(int i=1;i<=n;i++)
		cin>>w[i];
		for(int i=1;i<=n;i++)
		cin>>v[i];
		for(int i=1;i<=n;i++)
		for(int j=c;j>=w[i];j--)
		if(f[j-w[i]]+v[i]>f[j])
		f[j]=f[j-w[i]]+v[i];
		printf("%d\n",f[c]);
	}
	return 0;
}
