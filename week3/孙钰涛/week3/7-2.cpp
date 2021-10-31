#include<iostream>
#include<vector>
using namespace std;
int flag[501],point[501];
vector<int> connect[501];

int function(int x)
{
	flag[x]=1;
	if(point[x]!=0) return point[x];
	for(int i=0;i<connect[x].size();i++)
	{
		point[x]=point[x]+function(connect[x][i]);
	}
	return point[x];
}

int main()
{
	int n,m,x,y,Begin,End,fflag=1;
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		cin>>x>>y;
		connect[x].push_back(y);
	}
	cin>>Begin>>End;
	point[End]=1;
	cout<<function(Begin);
	cout<<" ";
	for(int i=1;i<=n;i++)
	{
		if(flag[i]!=0 && point[i]==0)
		{
			fflag=0;
			break;
		}
	}
	if(fflag==0) cout<<"No";
	else cout<<"Yes";
    return 0;
}