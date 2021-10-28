#include <bits/stdc++.h>
using namespace std;
int n,m,x,y,k,np,z,pd[10001];
vector<int>a[10001];
int panduan()
{
	for(int i=1;i<=n;i++)
	{
	if(pd[i]==1)
	{
		continue;
	}
	for(int j=0;j<a[i].size();j++)
	{
		if(pd[a[i][j]]==0)
		return 0;
	}
    }
	return 1;
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>x>>y;
		a[x].push_back(y);
		a[y].push_back(x);
	}
	cin>>k;
	for(int i=1;i<=k;i++)
	{
		memset(pd,0,sizeof(pd));
		cin>>np;
		for(int i=1;i<=np;i++)
		{
			cin>>z;
			pd[z]=1;
		}
	if(panduan()==1)
	cout<<"YES"<<endl;
	else if(panduan()==0)
	cout<<"NO"<<endl;
	}
	return 0;
}
