#include <bits/stdc++.h>
using namespace std;
int N,M;
int sinway[500][500];
int statement[550];//ʵ�ּ��仯����¼ÿһ�����жϡ��ڵ��ͨ·��������ܳ�ʱ 
int flag=1;
long long sum=0;
int judge(int start)
{
	if(statement[start])
	return statement[start];
	int j=0;//�ж��Ƿ�����·������������·�����޷�����if���Ӷ���for��j��ȻΪ0 
	for(int i=1;i<=N;i++)
	{
		if(sinway[start][i])
		{
			statement[start]+=judge(i);
			j=1;//��ӡϵͳ�� 
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
	statement[final]=1;//�յ㴦��ǳ�1��ֻ�е��������յ��ͨ·�Ż���� 
	cout<<judge(start)<<" ";
	if(!flag)
	cout<<"No"<<endl;
	else
	cout<<"Yes"<<endl;
	return 0;
}
