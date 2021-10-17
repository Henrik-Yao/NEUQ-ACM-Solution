#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,m,fx,x,t;
	int cx[100001];
	string a[100001];
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>cx[i]>>a[i];
	}
	t=1;
	for(int i=1;i<=m;i++)
	{
		cin>>fx>>x;
		if(fx==0&&cx[t]==0)
		{
			t--;
			if(t==0)
			t=n;
		}
		else if(fx==0&&cx[t]==1)
		{
			t++;
			if(t==9)
			t=1;
		}
		else if(fx==1&&cx[t]==0)
		{
			t++;
			if(t==9)
			t=1;
		}
		else if(fx==1&&cx[t]==1)
		{
			t--;
			if(t==0)
			t=n;
		}
	}
	cout<<a[t];
	return 0;
}
