#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,a[1001],ans=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		if(a[i+1]-a[i]==1)
		{
			ans++;
		}
	}
	cout<<ans;
	return 0; 
}
