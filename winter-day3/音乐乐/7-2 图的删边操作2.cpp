#include<bits/stdc++.h> 
using namespace std;
set<int>setting[20001];
set<int>::iterator j;
int arr[20001][20001];
int m;
struct edge
{
	int to;
	int next;
	int w;
}e[1001];
void add(int x,int y,int z)
{
	++m;
	setting[x].insert(y);
	arr[x][y]=z;
}
void erase(int x,int y)
{
	setting[x].erase(y);
}

int main()
{
	int n,ed,i;
	cin>>n>>ed;
	for(i=1;i<=ed;i++)
	{
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		add(x,y,z);
	}
	int k;
	cin>>k;
	while(k--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		erase(a,b);
	}
	//for(i=0;i<n;i++)
		//cout<<i<<' '<<v[i].size()<<endl;
	for(i=0;i<n;i++)
	{
		if(setting[i].size())
		{
			int cap=setting[i].size();
			cout<<i<<':';
			for(j=setting[i].begin();j!=setting[i].end();j++)
			{
				cout<<"("<<i<<","<<*j<<","<<arr[i][*j]<<")";
			} 
			cout<<endl;
		}
	}
	return 0;
}
