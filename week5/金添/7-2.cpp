#include <bits/stdc++.h>
using namespace std;
bool judge(int a)
{
	bool flag=1;
	for(int j=2;j<=sqrt(a);j++)
	{
		if(a%j==0)
		{
			flag=0;
			break;
		}
	}
	return flag;
}
int main()
{
	int num,remp,ans;
	cin>>num;
	for(int i=1;i<=num;i++)
	{
		cin>>remp;
		if(remp%2==0)//ÿ����С��6��ż��������������֮��
		{
			ans=2;
		}
		else
		{
			if(judge(remp))
			{
				ans=1;//�����������Լ� 
			}
			else
			{
				if(judge(remp-2))
				ans=2;
				else
				ans=3; 
			}
		}
		cout<<ans<<endl;
	}
	
	
	return 0;
}
