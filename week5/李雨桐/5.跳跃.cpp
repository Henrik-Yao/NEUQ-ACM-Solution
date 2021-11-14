#include<bits/stdc++.h>
using namespace std;

int n,m;
int a[50005];
bool vis[50005] = {false};
bool flag = false;

void dfs(int k);

int main()
{
	cin>>n;

	for(int i=0;i<n;i++)
    {
		cin>>a[i];
	}

	cin>>m;
	dfs(m);

	if(flag)
		cout<<"True";
	else
		cout<<"False";
}

void dfs(int k)
{
	if(flag||k<0||k>=n||vis[k])
        return;
	if(a[k] == 0)
	{
		flag=true;
		return;
	}
	vis[k] = true;
	dfs(k+a[k]);
	dfs(k-a[k]);
}

