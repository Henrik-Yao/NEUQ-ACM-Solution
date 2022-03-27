#include<bits/stdc++.h>
using namespace std;
list<int> L;
list<int>::iterator it;
set<list<int> > q;
int a[1000];int n;
void dfs(int x,list<int> l)
{
	if(l.size()>=2)
	{
		q.insert(l);
///		for(it=l.begin();it!=l.end();it++)
//		cout<<*it<<" ";
//		cout<<endl;
	}
	if(x==n)
	return;
	for(int i=x;i<n;i++)
	{
		if(l.size()==0||a[i]>=l.back())
		{
			l.push_back(a[i]);
			dfs(i+1,l);
			l.pop_back();
		}
	}
}
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];	
	}
	dfs(0,L);
	cout<<q.size();
} 
