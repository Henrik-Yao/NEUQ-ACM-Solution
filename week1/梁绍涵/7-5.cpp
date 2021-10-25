#include<bits/stdc++.h>
using namespace std;
struct student
{
	int face;
	string name;
}stu[1000100];
int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>stu[i].face>>stu[i].name;
	}
	int k=1;
	for(int i=1;i<=m;i++)
	{
		int x,y;
		cin>>x>>y;
		if(stu[k].face==0)
		{
			if(x==0)
			{
				if(k-y<=0)
				k=k-y+n;
				else
				k=k-y;
			}
			else
			{
				if(k+y>n)
				{
					k=k+y-n;
				}
				else
				{
					k=k+y;
				}
			}
		}
		else
		{
			if(x==1)
			{
				if(k-y<=0)
				k=k-y+n;
				else
				k=k-y;
			}
			else
			{
				if(k+y>n)
				{
					k=k+y-n;
				}
				else
				{
					k=k+y;
				}
			}
		}
	}
	cout<<stu[k].name;
}
