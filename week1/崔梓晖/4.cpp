#include <bits/stdc++.h>
using namespace std;
int n,ans=0;
void dfs(int x)
{
	if(x==1)
	{
		ans++;
		return;
	}
	else 
	{
		for(int i=1;i<=x-1;i++)
		{
			if(i==x)
			{
				continue;
			}
			else 
			if(x%i==0)
			{
				dfs(i);
			}
		}
	}
}
int main()
{
	cin>>n;
	dfs(n);
	cout<<ans*2;
	return 0;
}



