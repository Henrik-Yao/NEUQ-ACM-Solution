#include<iostream>
using namespace std;

bool citys[101];//这个城市是否安全
bool used[101];//这个城市是否已经来到过 
int to_ci;//城市总数
int road[101][100];//联通道路总数 

bool dfs(int area, int order, bool strat)
{
	if((!strat)&&(!citys[area]))	return false;//搜索到不安全的城市 
	if(used[area])	return false;
	if(area==order)	return true;
	//cout<<"搜索"<<area<<"号城市"<<endl;
	used[area]=true;
	for(int i=0; i<100; i++)
	{
		//cout<<"搜索连通"<<area<<"和"<<i<<"城市的道路"<<endl;
		if(road[area][i]==-1)
		{
			//cout<<"road["<<area<<"]["<<i<<"]=false!"<<endl;
			used[area]=false;
			return false;
		}
		//cout<<"找到"<<area<<"和"<<i<<"城市的道路"<<endl;
		if(dfs(road[area][i], order, false))	return true;
	}
	used[area]=false;
	return false;
}

int main()
{
	int save_city, to_road;
	cin>>to_ci>>save_city>>to_road;
	for(int i=0; i<101; i++)
	for(int j=0; j<100; j++)
		road[i][j]=-1;

	for(int i=0; i<save_city; i++)
	{
		int num;
		cin>>num;
		citys[num]=true;
	}
	for(int i=0; i<to_road; i++)
	{
		int s, e;
		cin>>s>>e;
		//if(citys[s]==false)	continue;//一个城市不安全
		//if(citys[e]==false)	continue;//另一个城市不安全
		if(s<0||s>100)	continue;//不合规范
		if(e<0||e>100)	continue;//不合规范
		//cout<<"将添加"<<s<<"和"<<e<<"城市的通路"<<endl;
		for(int j=0; j<100; j++)
		if(road[s][j]==-1)
		{
			//cout<<"road["<<s<<"]["<<j<<"]=true"<<endl;
			road[s][j]=e;
			break;
		}
		for(int j=0; j<100; j++)
		if(road[e][j]==-1)
		{
			//cout<<"road["<<e<<"]["<<j<<"]=true"<<endl;
			road[e][j]=s;
			break;
		}
	}
	int begin, final;
	cin>>begin>>final;
	if(citys[final]==false)
	{
		cout<<"The city "<<final<<" is not safe!";
		return 0;
	}
	if(dfs(begin,final,true))	cout<<"The city "<<final<<" can arrive safely!";
	else	cout<<"The city "<<final<<" can not arrive safely!";
	return 0;
}
