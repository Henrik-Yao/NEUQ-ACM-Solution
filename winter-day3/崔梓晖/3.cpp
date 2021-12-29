#include <bits/stdc++.h>
using namespace std;
set< list<int> >s;//set集合，自带去重和排序 
list<int> l;//双链表，可以前后都查询的数据结构 
int n,num[100];
void dfs(int x)
{
	if(x==n)
	{
		if(l.size()>=2)
		{
			s.insert(l);
		}
		return;
	}
	if(!l.size()||num[x]>=l.back())//l.back()查询链表最后一个元素 
	{
		l.push_back(num[x]);
		dfs(x+1);
		l.pop_back();
	}
	if(!l.size()||num[x]!=l.back())
	{
		dfs(x+1);
	}
}
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>num[i];
	}
	dfs(0);
	int ans=s.size();
	cout<<ans<<endl;
	return 0;
}
