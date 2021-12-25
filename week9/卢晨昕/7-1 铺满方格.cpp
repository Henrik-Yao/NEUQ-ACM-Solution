#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n;
ll f[105];
int main()
{
	f[1]=1;
	f[2]=2;
	f[3]=4;
	for(int i=4;i<=51;i++)f[i]=f[i-1]+f[i-2]+f[i-3]; 
	while(scanf("%d",&n)!=EOF)
	{
		cout<<f[n]<<endl;
	}
	return 0;
}
