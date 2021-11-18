#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,a;
	cin>>n;
	while(n--)
	{
		cin>>a;
		int flag1=0;
		int flag2=0;
		for(int i=2;i<=sqrt(a);i++)
		{
			if(a%i==0)
			{
				flag1=1;      
				break;
			}
		}
		for(int i=2;i<=sqrt(a-2);i++)
		{
			if((a-2)%i==0)
			{
				flag2=1;      
				break;
			}
		}
		if(flag1==0)
		{
			cout<<"1"<<endl;
		}
		if(flag1==1&&flag2==1)
		{
			if(a%2==0)
			{
				cout<<"2"<<endl;
			}
			else cout<<"3"<<endl;
		}
		if(flag1==1&&flag2==0)
		{
			cout<<"2"<<endl;
		}
	}
	return 0;
}
