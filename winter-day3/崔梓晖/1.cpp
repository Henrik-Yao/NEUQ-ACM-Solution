#include <bits/stdc++.h>
using namespace std;
vector<pair<int,int> >m[20001];
int main()
{
	int n,e,a,b,c;
	cin>>n>>e;
	for(int i=1;i<=e;i++)
	{
		cin>>a>>b>>c;
		m[a].push_back(make_pair(b,c));
	}
	for(int i=0;i<=n;i++)
	{
		if(m[i].size()==0)
		{
			continue;
		}
		else 
		{
			cout<<i<<":";
			sort(m[i].begin(),m[i].end());
			for(int j=0;j<m[i].size();j++)
			{
				cout<<"("<<i<<","<<m[i][j].first<<","<<m[i][j].second<<")";
			}
			cout<<endl;
		}
	}
	return 0;
}
