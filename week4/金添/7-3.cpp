#include <iostream>
using namespace std;
bool visit[10000001]={1,1};//0,1�������� 
int prime[7000000];
int main()
{
	int n;
	cin>>n;
	int num=0;//��¼�����ĸ��� 
	for(int i=2;i<=n;i++)//���� 
	{
		if(!visit[i])
		prime[++num]=i;
		//�ؼ��㣺�������Ǳ������ı���ʱ��ֹͣɸ
		for(int j=1;j<=num;j++)//������ 
		{
			if((prime[j]*i)>n) break;
			int remp=prime[j]*i;
			visit[remp]=1;
			if(i%prime[j]==0)
			{	
				break;
			}
		} 
	}
	cout<<num<<endl;
	
	return 0;
} 
