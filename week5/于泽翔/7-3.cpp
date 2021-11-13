#include<bits/stdc++.h>
using namespace std;
int book[20020];
vector<int> v[20020];

void dfs(int cur)
{
	cout<<cur<<' ';
	book[cur]=1;
    
	for (int i=0; i<v[cur].size(); i++)
		if (book[v[cur][i]]==0)
			dfs(v[cur][i]);
}
int main()
{
	int n, e;
	cin>>n>>e;
	int a, b;
	for (int i = 1;i <= e;i++)
    {
		cin>>a>>b;
		v[a].push_back(b);
	}
	for (int i=0; i<n; i++)
		sort(v[i].begin(), v[i].end());
	
	for(int i=0; i<n; i++)
        if(book[i]==0)
            dfs(i);
}