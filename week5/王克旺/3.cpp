#include<bits/stdc++.h>
using namespace std;
vector<int>d[20001];
int n,e,vis[20001];
void dfs(int n) 
{
	int i,length;
	cout<<n<<" ";
	vis[n]=1;
	length=d[n].size();
	for(i=0;i<length;i++)
	{
		if(vis[d[n][i]]==0)
		{
			dfs(d[n][i]);
		}
	}
}
int main()
{
	int i;
	cin>>n>>e;
	for(i=0;i<e;i++)
	{
		int a,b;
		cin>>a>>b;
		d[a].push_back(b);
	}
	for(i=0;i<n;i++) 
	{
		sort(d[i].begin(),d[i].end());
	}
	for(i=0;i<n;i++)
	{
        if(vis[i]==0)
        {
            dfs(i);        	
		}
    }
    return 0;
}
