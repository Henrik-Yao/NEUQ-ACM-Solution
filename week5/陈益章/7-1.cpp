#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
const int maxh=10e4+5;
vector<int> zupu[maxh];
char sex[maxh];
bool vis[maxh];
int flag=0;
void dfs(int x,int num)
{
	if (num>=4)
	return ;
	for (int i=0;i<zupu[x].size();i++)
	{
		if(vis[zupu[x][i]]==0)
		{
		vis[zupu[x][i]]=1;
		dfs(zupu[x][i],num+1);
	}
		else
		{
			flag=1;
			return ;
		}
	}
}
int main()
{
	int n,fa,ma,id;
	cin>>n;
	for (int i=0;i<n;i++)
	{
		cin>>id;
		cin>>sex[id];
		cin>>fa>>ma;
		if (fa!=-1)
		{
			zupu[id].push_back(fa);
			sex[fa]='M'; 
		} 
		if (ma!=-1)
		{
			zupu[id].push_back(ma);
			sex[ma]='F'; 
		} 
	}
	cin>>n;
	for (int i=0;i<n-1;i++)
	{
		int a,b;
		flag=0;
		cin>>a>>b;
		if (sex[a]==sex[b])
			cout<<"Never Mind"<<endl;
		else {
			memset(vis,0,sizeof(vis));
		dfs(a,0);
		dfs(b,0);
		if (flag==0)
		cout<<"Yes"<<endl;
		else
		cout<<"No"<<endl;
		}
	}
    int a,b;
		flag=0;
		cin>>a>>b;
		if (sex[a]==sex[b])
			cout<<"Never Mind";
		else {
			memset(vis,0,sizeof(vis));
		dfs(a,0);
		dfs(b,0);
		if (flag==0)
		cout<<"Yes";
		else
		cout<<"No";
		}
	return 0;
}
	
 
