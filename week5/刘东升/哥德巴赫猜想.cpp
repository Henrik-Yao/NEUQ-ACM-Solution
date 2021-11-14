#include<bits/stdc++.h>
using namespace std;
int zhi(int g)//判断是否为质数 
{
	int flag=0;
	for(int i=2;i<=sqrt(g);i++)
	{
		if(g%i==0)
		{
			flag=1;
		}
	}
	return flag;
}
int main()
{
	int n;
	cin>>n;
	while(n--)
	{
		int g;
		cin>>g;	
		if(g%2==0) //如果为偶数，则猜想 
		{
			cout<<"2"<<endl;
		}
		else//奇数进行分类讨论 
		{
			if(zhi(g)==0)//直接是质数 
			{
				cout<<"1"<<endl;
			}
			else//剩下可拆成偶质数2+另外质数 或者三个奇数和（因为该数大于6，所以必能拆成3+一个偶数的形式 ，偶数必能拆成俩奇质数（猜想得）） 
			{
				if(zhi(g-2)==0) 
				{
					cout<<"2"<<endl;
				}
				else
				{
					cout<<"3"<<endl;
				}
			}
		}
	}
}
