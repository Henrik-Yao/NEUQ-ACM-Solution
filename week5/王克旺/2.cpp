#include<iostream>
#include<cmath>
using namespace std;
int sushu(int a)
{
	int i;
	for(i=2;i<=sqrt(a);i++)
	{
		if(a%i==0)
		{
		    return 0;
		}
	}
	return 1;
}
int main()
{
	int n,j;
	cin>>n;
	int b[n];
	for(j=0;j<n;j++)
	{
		int a,i,flag=1;
		cin>>a;
		if(a%2==0)
		{
			b[j]=2;
		}
		else
		{
			if(sushu(a))
			{
				b[j]=1;
			}
			else
			{
				if(sushu(a-2))
				{
					b[j]=2;
				}
				else
				{
					b[j]=3;
				}
			}
		}
	}
	for(j=0;j<n-1;j++)
	{
		cout<<b[j]<<endl;
	}
	cout<<b[n-1];
	return 0;
}
