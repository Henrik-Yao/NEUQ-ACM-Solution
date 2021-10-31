#include<bits/stdc++.h>
using namespace std;
vector<int> Map[10010];
int map1[10010];
int main()
{
 	int n,m;
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int ui,vi;
		cin>>ui>>vi;
		Map[ui].push_back(vi);
	}
	int t;
	cin>>t;
	while(t--)
	{
		int num;
		cin>>num;
		memset(map1,0,sizeof(map1));
		for(int i=1;i<=num;i++)
		{
			int s;
			cin>>s;
			map1[s]=1;
		}
		int flag=1;
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<Map[i].size();j++)
			{
				if(map1[Map[i][j]]==1||map1[i]==1) continue;
				else
				{
					cout<<"NO"<<endl;
					flag=0;
					break;
				}	
			}
			if(flag==0)
			break;
		}
		if(flag==1) cout<<"YES"<<endl;
	}
}


