#include <bits/stdc++.h>
using namespace std;

bool vis[10000010];

int main(void)
{
	memset(vis, 0, 10000010);
	int n, ans=0;
	cin>>n;
	for(int i=2; i<=n; i++)
	{
		if(vis[i])
			continue;
		ans++;
		for(int j=i; j<=n; j+=i)
			vis[j]=1;
	}
	cout<<ans;
	
	return 0;
}