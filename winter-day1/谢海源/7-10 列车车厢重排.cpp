#include<bits/stdc++.h>
using namespace std;
queue<int>l[101];
queue<int>ent;
int a[101];
int main()
{
	int n,x,s=1;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>x;
		ent.push(x);
	}
	while(!ent.empty())
	{
		int t=ent.front();
		for(int i=0;i<=s;i++)
		{
			if(l[i].empty()||l[i].back()>t)
			{
				if(l[i].empty())s++;
				l[i].push(t);
				ent.pop();
				break;
			}
		}
	}
	while(!l[0].empty())
	{
		if(l[0].size()>1)cout<<l[0].front()<<" ";
		else cout<<l[0].front();
		l[0].pop();
	}
	cout<<endl;
	cout<<s-1;
	cout<<endl;
	return 0;
}