#include<bits/stdc++.h>
using namespace std;
const int M=20001;
bool judge[M];//评判，最开始都是空的 
vector<int>infer[M];//用vector引入一个有向队列 
void dfs(int n);
int main()
{
	int n,T,first,second;
	cin>>n>>T;
	while(T--)
	{
		scanf("%d %d",&first,&second);
		infer[first].push_back(second);//将第一个指向第二个 
	}
	for(int i=0;i<n;i++)//从每一点试图进入 
	{
		if(judge[i]==0)
		{
			dfs(i);//如果没有遍索过 
		}
	}
}
void dfs(int n)
{
	int k;
    cout<<n<<" ";
	judge[n]=1;//标记已经遍索过 
	sort(infer[n].begin(),infer[n].end());//从头排序到尾 
	for(auto k:infer[n])//按值传递 
	{
		if(judge[k]==0)
		{
			dfs(k);
		} 
	}
}
