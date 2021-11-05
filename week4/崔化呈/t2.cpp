#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,m;
	long long f[50];
	cin>>n;
	f[1]=1;f[2]=1;
	for(int i=3;i<50;i++)
	{
		f[i]=f[i-1]+f[i-2];
	}
    f[1]=0;
	for(int i=1;i<=n;i++)
	{
		cin>>m;
		cout<<f[m]<<endl;
	}
	
	return 0;
}
