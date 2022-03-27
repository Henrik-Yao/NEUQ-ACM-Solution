#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n, m;
	cin>>n>>m;
	map<int,map<int,int>>MAP;
	for (int i=0;i<m;i++)
	{
		int a,b,c;
		cin>>a>>b>>c;
		MAP[a][b]=c;
	}

	int t;
	cin>>t;

	for (int i=0;i<t;++i)
	{
		int a,b;
		cin>>a>>b;
		MAP[a].erase(b);
	}

	for (auto i:MAP)
	{
		int a=i.first;

		if(!i.second.empty())
            cout<<a<<":";

		for (auto j:i.second)
            cout<<"("<<a<<","<<j.first<<","<<j.second<<")";

		if(i.second.empty()==0)
            cout<< endl;
	}

	return 0;
}
