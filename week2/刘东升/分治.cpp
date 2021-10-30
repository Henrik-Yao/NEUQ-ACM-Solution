#include<bits/stdc++.h>
using namespace std;
const int M=10001;
typedef struct{
	int a;
	int b;
}City;
City city[M];//引入一个储存链接城市的结构体 
int judge[M];//引入一个判断摧毁城市的数列 
int main()
{
	int n,m,i;
	cin>>n>>m;
	for(i=0;i<m;i++)
	{
		cin>>city[i].a>>city[i].b;//导入链接城市的道路 
	}
	int N,CityNumber,target;
	cin>>N;
	while(N--)
	{
		cin>>CityNumber;
		bool flag=true;//引入判断是否能成功 
		memset(judge,0,sizeof(judge));//避免上一次的摧毁影响这次 
		for(i=0;i<CityNumber;i++)
		{
			cin>>target;
			judge[target]=1; //将摧毁的城市标记为1，未摧毁则不做处理为0 
		}
		for(i=0;i<m;i++)
		{
			if(!judge[city[i].a]&&!judge[city[i].b])//判断链接的两个城市是否存在，如果都存在则任务失败 
			{
				flag = false;
				break;
			}
		}
		if(flag)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}
