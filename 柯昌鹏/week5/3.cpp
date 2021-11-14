#include <bits/stdc++.h>
using namespace std;
//要注意排序的这一步，保证能在对应多个分支时从小的开始查找

vector<int > a[20010],res;
bool v[20010];

void dfs(int x)
{
    v[x]=1;//深搜打标 
    res.push_back(x);
    for(auto j:a[x])
    {
    	if(v[j]) continue;
    	dfs(j);
	}
}

int main ()
{
	int n,m,temp1,temp2;
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>temp1>>temp2;
		a[temp1].push_back(temp2);
	}
	for(int i=0;i<n;i++)
	{
		sort(a[i].begin(),a[i].end());
	}
	for(int i=0;i<n;i++)
	{
		if(v[i]) continue;
		dfs(i);
	}
	for(int i=0;i<n;i++) cout<<res[i]<<" ";
	return 0;
}