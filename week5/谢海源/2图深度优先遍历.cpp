#include<bits/stdc++.h>
using namespace std;
bool v[20005]={};
vector<int>infer[20005];//有向线段
void dfs(int n)
{
    cout<<n<<" ";
	v[n]=1;
	sort(infer[n].begin(),infer[n].end());//排序
	int k;
	for(auto k:infer[n])
	{
		if(v[k]==0) dfs(k);
	}
}
int main()
{
	int a,b;
	int n,e;
	cin>>n>>e;
	while(e--)
	{
		scanf("%d %d",&a,&b);
		infer[a].push_back(b);//由a指向b
	}
	for(int i=0;i<n;i++)
	{
		if(v[i]==0) dfs(i);
	}
    return 0;
}