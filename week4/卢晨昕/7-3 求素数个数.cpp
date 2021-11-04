#include<bits/stdc++.h>
#define ll long long
#define inf 0x7fffffff
using namespace std;
int n;
int ans;
bool v[10000005];
void su(int a)
{
	for(int i=2;i<=a;i++)
	{
		if(v[i])continue;
		ans++;
		for(int j=i;j<=a/i;j++)
		{
			v[i*j]=1;
		}
	}
}
int main()
{
	cin>>n;
	su(n);
	cout<<ans;
	return 0;
}
