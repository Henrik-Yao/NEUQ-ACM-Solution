#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long f[40];
	int n;
	f[1]=2;
	for(int i=2;i<=40;i++)
	{
		f[i]=f[i-1]+1+f[i-1]+1+f[i-1];
	}
	while(cin>>n)
	{
		cout<<f[n]<<endl;
	}
	return 0;
	
}
