#include<bits/stdc++.h> 
using namespace std;
int a[1000];
int F(int n)//进行有用项记录 
{
	if(n==1)
	{
		return 1;
	}
	int sum=0;
	if(a[n]==-1)
	{
		for(int i=1;i<=n/2;i++)
		{
			if(n%i==0)
			{
				sum=sum+F(i);//多次递归出数量 
			}
			a[n]=sum+1;
		}
		return a[n];
	}
	else return a[n];
}
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n+1;i++)
	{
		a[i]=-1;
	}
	printf("%d",F(n));
	return 0;
}
