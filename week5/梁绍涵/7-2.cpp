#include<bits/stdc++.h>
using namespace std;
int n,flag=0,ans=0;
int search(int m)
{
	int t=1,t1=1;
	if(m%2==0)
	{
		return 2;
	}
	for(int i=2;i<=sqrt(m);i++)
	{
		if(m%i==0)
		{
//			cout<<"?"<<i<<endl;
			t=0;
			break;
		}
	}
//	cout<<t<<endl;
	if(t==1)
	{
		return 1;
	}
	else
	{
		for(int i=2;i<=sqrt(m-2);i++)
		{
			if((m-2)%i==0)
			{
				t1=0;
				break;
			}
		}
		if(t1==0)
		{
			return 3;
		}
		else
		{
			return 2;
		}
	}
}
int main()
{
	int x;
	cin>>x;
	for(int i=1;i<=x;i++)
	{
		int num;
		cin>>num;
		if(num==2)
		{
			cout<<1<<endl;
			continue;
		}
		ans=0;
		cout<<search(num)<<endl;
	}
}
