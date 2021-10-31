#include <bits/stdc++.h>
using namespace std;
int n,m,pd=1,b[1001],s,e;
vector<int>a[1001];
int dfs(int k)
{
	if(b[k]!=-1)
	return b[k];
	if(k==e)
	{
		return b[k]=1;
	}
	if(a[k].size()==0)
	{
		pd=0;
		b[k]=0;
		return b[k];
    }
    int ans=0;
	for(int i=0;i<a[k].size();i++)
	{
		int next=a[k][i];
		ans=ans+dfs(next);
	}
	b[k]=ans;
	return b[k];
}
int main()
{
	memset(b,-1,sizeof(b));
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int s1,s2;
		cin>>s1>>s2;
		a[s1].push_back(s2);
	}
	cin>>s>>e;
	if(dfs(s)!=0&&pd==1)
	{
		cout<<dfs(s)<<" "<<"YES";
	}
	else cout<<dfs(s)<<" "<<"NO";
	return 0;
}
