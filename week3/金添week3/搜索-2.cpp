#include <bits/stdc++.h>
using namespace std;
int N,M;
int sinway[500][500];
int statement[550];//实现记忆化，记录每一个“判断”节点的通路个数，规避超时 
int flag=1;
long long sum=0;
int judge(int start)
{
	if(statement[start])
	return statement[start];
	int j=0;//判断是否有死路情况，如果有死路，则无法进入if，从而出for后j仍然为0 
	for(int i=1;i<=N;i++)
	{
		if(sinway[start][i])
		{
			statement[start]+=judge(i);
			j=1;//烙印系统！ 
		}
	}
	if(!j)
	flag=0;
	return statement[start];
}
int main()
{
	cin>>N>>M;
	for(int i=0;i<M;i++)
	{
		int remp1,remp2;
		cin>>remp1>>remp2;
		sinway[remp1][remp2]=1;
	}
	int start,final;
	cin>>start>>final;
	statement[final]=1;//终点处标记成1；只有到达真正终点的通路才会计入 
	cout<<judge(start)<<" ";
	if(!flag)
	cout<<"No"<<endl;
	else
	cout<<"Yes"<<endl;
	return 0;
}
