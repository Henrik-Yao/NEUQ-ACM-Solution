#include <bits/stdc++.h> 
using namespace std;
vector<int> vec[100000]; //关系图 
bool vis[100000],flag; 
char sex[100000]; 
void dfs(int x,int num) 
{
	if(num>=4){return;}   //五代 
	for(int i=0;i<vec[x].size();i++)
	{
		if(vis[vec[x][i]]==0)   //在x的亲戚中见过就是近亲 
		{
			vis[vec[x][i]]=1; 
			dfs(vec[x][i],num+1); 
		}
		else{flag=1;} 
	}
}
int main() 
{
	int n;
	cin>>n;
	while(n--)
	{
		int id,ba,ma;
		char xin;
		cin>>id>>xin>>ba>>ma;
		sex[id]=xin;
		if(ba!=-1)
		{ 
			vec[id].push_back(ba);  //id的上一代是ba,ma 
			sex[ba]='M';
		}
		if(ma!=-1)
		{
			vec[id].push_back(ma);
			sex[ma]='F';
		}
	}
	int k;
	cin>>k;
	while(k--)
	{
		int x,y;
		cin>>x>>y; 
		if(sex[x]==sex[y])
		{
			cout<<"Never Mind"<<endl;
		} 
		else
		{
			flag=0;  
			memset(vis,0,sizeof(vis));  //初始化 
			vis[x]=1;  
			vis[y]=1;
			dfs(x,0);
			dfs(y,0);
			if(flag){cout<<"No"<<endl;}	
			else{cout<<"Yes"<<endl;}			
		}
	}
	return 0;
	
}
