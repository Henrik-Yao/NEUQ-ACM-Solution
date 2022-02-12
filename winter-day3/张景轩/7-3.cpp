#include<iostream>
#include<map>
using namespace std;

int graph[20];
int ans=0;
int n;
map<string,int> mp;
string func(int x)
{
	string ans="";
	while(x!=0)
	{
		int t = x%10;
		x = x / 10;
		ans=(char)(t+48)+ans;
	}
	return ans;
}
void dfs(int x,string s)
{
	for(int i=x+1;i<=n;i++)
	{
		if(graph[i]>=graph[x])
		{
			string str=s+func(graph[i]+200);
			if(!mp[str])
			{
				mp[str]=1;
				ans++;
			}
			dfs(i,str);
		}
	}
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
        cin>>graph[i];
    }
	for(int i=1;i<n;i++)
	{
        dfs(i,func(graph[i]+200));
    }
	cout<<ans;
}