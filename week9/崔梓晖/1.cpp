#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,m,a[10010],dir[10010],maxx;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	maxx=a[n]-a[1]+1;
	for(int i=2;i<=n;i++)
	{
		dir[i-1]=a[i]-a[i-1];
	}
	sort(dir+1,dir+n);
	for(int i=1;i<m;i++)
	{
		maxx=maxx-dir[n-i]+1;
	}
	cout<<maxx;
	return 0;
}

