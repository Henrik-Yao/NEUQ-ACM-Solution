#include<bits/stdc++.h>
using namespace std;
struct student//记录学生信息 
{
	int number;
	string name;
};
int main()
{
	int n,m,i;
	cin>>n>>m;
	struct student a[n];
	for(i=0;i<n;i++)
	{
		cin>>a[i].number>>a[i].name;
	}
	i=0;
	while(m--)
	{
		int q,w;
		cin>>q>>w;
		if(q+a[i].number==1)//判断方向 
		{
			i=w+i;
			while(i>n)
			{
				i=i-n;
			}
		}
		else
		{
			i=i-w;
			while(i<0)
			{
				i=i+n;
			}
		}
	}
	cout<<a[i].name;
} 
