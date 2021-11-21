#include<bits/stdc++.h>
using namespace std;
bool isprime(int n)
{
	for(int i=2;i<=sqrt((double)n);i++)
	{
		if(n%i==0)
		{
			return 0;
		}
	}
	return 1;
}
int main()
{
	int n;
	cin>>n;
	while(n--)
	{
		int num;
		cin>>num;
		if(num%2==0)
		{
			cout<<"2"<<endl;
		}
		else
		{
			if(isprime(num))
			{
				cout<<"1"<<endl;
			}
			else if(isprime(num-2))
			{
				cout<<"2"<<endl;
			}
			else
			{
				cout<<"3"<<endl;
			}
		}
	}
	return 0;
}
