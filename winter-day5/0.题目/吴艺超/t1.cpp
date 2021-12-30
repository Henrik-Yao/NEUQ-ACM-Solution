#include<bits/stdc++.h>
using namespace std;
int n,ans;
int a[10010];
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++)
	{
		if(a[i]-a[i-1]==1)
		ans++;
	}
	cout<<ans;
} 
