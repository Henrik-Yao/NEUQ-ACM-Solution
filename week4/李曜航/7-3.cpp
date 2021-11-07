#include<bits/stdc++.h>
using namespace std;
bool vis[10000001];
int main()
{
	int b;
	long long ans=0;
	cin>>b;
	for(int i=2;i<=b;i++)
	{
		if(vis[i]==0)
		{
			ans++;
			for(int j=i;j<=b;j+=i)
			    vis[j]=1;
		}		
	}
	cout<<ans;
}