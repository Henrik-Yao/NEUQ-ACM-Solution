#include<bits/stdc++.h>
using namespace std;
int zhi(int g)//�ж��Ƿ�Ϊ���� 
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
		if(g%2==0) //���Ϊż��������� 
		{
			cout<<"2"<<endl;
		}
		else//�������з������� 
		{
			if(zhi(g)==0)//ֱ�������� 
			{
				cout<<"1"<<endl;
			}
			else//ʣ�¿ɲ��ż����2+�������� �������������ͣ���Ϊ��������6�����Ա��ܲ��3+һ��ż������ʽ ��ż�����ܲ����������������ã��� 
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
