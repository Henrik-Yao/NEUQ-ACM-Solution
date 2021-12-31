#include<bits/stdc++.h>
#include<string>
using namespace std;
int n,x[10000],ans[1000],vis[10000];string a;
void dfs(int k)
{
	if(k==n)
	{	
		for(int i=0;i<k;i++)
		cout<<char(ans[i]+97);
		cout<<endl;
		return;
	}
	for(int i=0;i<n;i++)
	{
		if(vis[i]==0)
		{
			vis[i]=1;
			ans[k]=x[i];
			dfs(k+1);
			vis[i]=0;
		}
	}
}
int main()
{	
	string p;
	cin>>a;
	n=a.size();
	for(int i=0;i<n;i++)
	x[i]=a[i]-97;
	sort(x,x+n);
	dfs(0);
}
