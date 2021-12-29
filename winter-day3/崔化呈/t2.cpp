#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,e,a,b,w;
	map<int,map<int,int> >mp;
	cin>>n>>e;
	for(int i=0;i<e;i++)
	{
		cin>>a>>b>>w;
		mp[a][b]=w;
	}
	int k;
	cin>>k;
	for(int i=0;i<k;i++)
	{
		cin>>a>>b;
		mp[a].erase(b);
	}
	for(auto i:mp)
	{
		a=i.first;
		if(!i.second.empty()){cout<<a<<":";} 
		for(auto j:i.second)
		{
			printf("(%d,%d,%d)",a,j.first,j.second);
		}
		if(!i.second.empty()){cout<<endl;}
	}
	return 0;
}
