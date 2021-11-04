#include <bits/stdc++.h>
using namespace std;
int main()
{
	long long n,m,f[10001];
	cin>>n;
	while(n--)
	{
	    f[1]=0;
		f[2]=1;
		f[3]=2; 
		cin>>m;
		for(int i=4;i<=m;i++)
		f[i]=f[i-1]+f[i-2];
		cout<<f[m]<<endl;
	}
	return 0;
}
