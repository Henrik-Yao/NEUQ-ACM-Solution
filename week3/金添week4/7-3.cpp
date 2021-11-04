#include <iostream>
using namespace std;
bool visit[10000001]={1,1};//0,1不是素数 
int prime[7000000];
int main()
{
	int n;
	cin>>n;
	int num=0;//记录素数的个数 
	for(int i=2;i<=n;i++)//乘数 
	{
		if(!visit[i])
		prime[++num]=i;
		//关键点：当乘数是被乘数的倍数时，停止筛
		for(int j=1;j<=num;j++)//被乘数 
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
