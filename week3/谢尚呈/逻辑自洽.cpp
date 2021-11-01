#include<iostream>
using namespace std;

int question[501];
int road[501][501];
bool serd[501];
bool receive=true;

int dfs(int area, int order)
{
	if(area==order)	return 1;
	if(serd[area])	return question[area];
	int times_no_dfs=0;
	for(int i=0; i<501; i++)
	{
		if(road[area][i]==-1)	break;
		int num=dfs(road[area][i], order);
		if(num==0)	times_no_dfs+=1;
		question[area]+=num;
	}
	if(times_no_dfs)
	if(question[area])
		receive=false;
	if(question[area]==0)	receive=false;
	serd[area]=true;
	return question[area];
} 

int main()
{
	int n, m;
	for(int i=0; i<501; i++)
	for(int j=0; j<501; j++)
		road[i][j]=-1;
	cin>>n>>m;
	for(int i=0; i<m; i++)
	{
		int s, e;
		cin>>s>>e;
		if(s<0||s>501)	continue;
		if(e<0||e>501)	continue;
		for(int j=0; j<501; j++)
		if(road[s][j]==-1)
		{
			road[s][j]=e;
			break;
		}
	}
	int s, e;
	cin>>s>>e;
	int num=dfs(s, e);
	cout<<num;
	if(receive)	cout<<" Yes"<<endl;
	else	cout<<" No"<<endl;
	return 0;
}
