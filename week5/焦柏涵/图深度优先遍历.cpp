#include <bits/stdc++.h>
using namespace std;
//int num[200000]={0},w[200000]={0},vised[200000]={0},n,e;
int vised[200000]={0};
vector<int> m[20000],sum;
void ss(int x)
{
	/*if(num[x]==0||vised[x]==1) return;
	vised[x]=1;
	for(;w[x]<num[x];w[x]++)
	{
		if(vised[m[x][w[x]]]==1) continue;
		cout<<m[x][w[x]]<<" ";
		ss(m[x][w[x]]);
		num[x]--;
	}*/
	vised[x]=1;
	sum.push_back(x);
	for(auto y:m[x])//dev不能识别，我吐了 
	{
		if(vised[y]==1) continue;
		ss(y);
	}
}
int main()
{
	int n,e;
	cin>>n>>e;
	while(e>0)
	{
		int a,b;
		cin>>a>>b;
		m[a].push_back(b);
		sort(m[a].begin(),m[a].end());
		//num[a]++;
		e--;
	}
	for(int i=0;i<n;i++)
	{
		if(vised[i]!=1) ss(i);
	}
	for(int i=0;i<sum.size();i++)
	{
		cout<<sum[i]<<" ";
	}
	return 0;
}
