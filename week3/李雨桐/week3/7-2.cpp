#include<bits/stdc++.h>

using namespace std;

vector <int> Vector[505];
int n,m,ans,a,b;
int vis[505], Map[505];

int dfs(int x)
{
	vis[x] = 1;
	if(Map[x])
        return Map[x];
	for(auto i: Vector[x])
    {
		Map[x] += dfs(i);
	}
	return Map[x];
}

int main()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
    {
		cin>>a>>b;
		Vector[a].push_back(b);
	}
	cin>>a>>b;
	Map[b] = 1;
	ans = dfs(a);

	int flag = 1;
	for(int i=1;i<=n;i++)
    {
		if(vis[i]==1 && Map[i]==0) {
			flag = 0;
			break;
		}
	}
	cout<<ans<<" ";

	if(flag==1)
		cout<<"Yes";
	else
		cout<<"No";
}
