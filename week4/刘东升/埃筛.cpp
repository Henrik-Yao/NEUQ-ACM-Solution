#include<bits/stdc++.h>
using namespace std;
const int M=10001;
int a[M];
int main()
{
	memset(a,0,M);//��֤�����ʼ����0 
	for(int i=2;i<=M;i++)
	{
		if(!a[i])//���Ϊ0��֤��֮ǰû�б�ɸ����˵�������� 
		{
			for(int j=i*i;j<=M;j+=i)//������������ı��� 
			{
				a[j]=1;
			}
		}
	}
	int c,b;
	while(cin>>c>>b)
	{
		int m=0;
		for(int i=c;i<=b;i++)
		{
			if(!a[i])
			{
				if(m!=0)
				{
					cout<<" ";
				}
				cout<<i;
				m=1;
			}
		}
		cout<<endl;
	}
}
