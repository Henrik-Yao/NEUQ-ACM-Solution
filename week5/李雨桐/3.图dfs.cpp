#include<bits/stdc++.h>
using namespace std;
vector<int> a[20005];

int vis[20005]; int n,m,sum;

void dfs(int t)
{
	int i;
	cout<<t<<" ";
	vis[t] = 1;

	for(int i=0;i<a[t].size();i++){

		if (vis[a[t][i]]==0)
		{

			dfs(a[t][i]);

		}
	}

}

int main()
{

	int t1,t2;
	cin>>n>>m;

	for(int i=0;i<m;i++)
    {
		cin>>t1>>t2;
		a[t1].push_back(t2);
	}

	for(int i=0;i<n;i++)
    {
		sort(a[i].begin(),a[i].end());
	}

	for(int i=0;i<n;i++)
    {
		if(vis[i] == 0)
			dfs(i);
	}
	return 0;
}
