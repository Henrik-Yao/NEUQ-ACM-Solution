#include <bits/stdc++.h>
using namespace std;
vector<pair<int,int> >m[20001];
int main()
{
	int n,e,a,b,c,k;
	cin>>n>>e;
	for(int i=1;i<=e;i++)
	{
		cin>>a>>b>>c;
		m[a].push_back(make_pair(b,c));
	}
	cin>>k;
	for(int i=1;i<=k;i++)
	{
		cin>>a>>b;
		for(int j=0;j<m[a].size();j++)
		{
			if(m[a][j].first==b)
			{
				m[a][j].first=-1;
			}
		}
	}
	for(int i=0;i<=n;i++)
	{
		if((m[i].size()==1&&m[i][0].first==-1)||(m[i].size()==0))
		{
			continue;
		}
		else 
		{
			cout<<i<<":";
			sort(m[i].begin(),m[i].end());
			for(int j=0;j<m[i].size();j++)
			{
				if(m[i][j].first==-1)
				{
					continue;
				}
				else cout<<"("<<i<<","<<m[i][j].first<<","<<m[i][j].second<<")";
			}
			cout<<endl;
		}
	}
	return 0;
}
