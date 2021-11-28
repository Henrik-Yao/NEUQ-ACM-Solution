#include<bits/stdc++.h>
using namespace std;
int n,m;
map<string,string> q;
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		string x,y;
		cin>>x>>y;
		q[y]=x;
	}
	for(int i=1;i<=m;i++)
	{
		string a;
		cin>>a;
		if(q.find(a)!=q.end())
		{
			cout<<q[a]<<endl;
		}
		else
		{
			cout<<"eh"<<endl;
		}
	}
}
