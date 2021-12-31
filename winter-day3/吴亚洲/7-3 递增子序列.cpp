#include<bits/stdc++.h>
using namespace std;
int a[20];
int ans=0;
int n;
map<string,int>_map;
string tra(int x)
{
	string ans="";
	while(x!=0)
	{
		int t=x%10;
		x/=10;
		ans=(char)(t+48)+ans;
	}
	return ans;
}
void dfs(int t,string s)
{
	for(int i=t+1;i<=n;i++)
	{
		if(a[i]>=a[t])
		{
			string ss=s+tra(a[i]+200);
			if(!_map[ss])
			{
				_map[ss]=1;
				ans++;
			}
			dfs(i,ss);
		}
	}
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	for(int i=1;i<n;i++)
	dfs(i,tra(a[i]+200));
	cout<<ans;
}
