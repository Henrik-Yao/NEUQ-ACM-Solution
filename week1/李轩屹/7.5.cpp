#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,m,bh=1;
	cin>>n>>m;
	int a[n+1];
	string s[n+1];
	for(int i=1;i<=n;i++) cin>>a[i]>>s[i];
	for(int j=1;j<=m;j++)
	{
		int x,y;
		cin>>x>>y;
		if(a[bh]==0) 
		{
			if(x==0) bh=bh-y+n;
			else bh=bh+y;
			if(bh>n) bh-=n;
		}
		else if(a[bh]==1) 
		{
			if(x==1) bh=bh-y+n;
			else bh=bh+y;
			if(bh>n) bh-=n;
		}		
	}
	cout<<s[bh];
	return 0;
}
