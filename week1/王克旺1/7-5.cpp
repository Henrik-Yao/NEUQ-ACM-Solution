#include<iostream>
#include<string>
using namespace std;
struct student
{
	int face;
	string name;
}a[100001];
int main()
{
	int m,n,i,j,num=1;
	cin>>n>>m;
	int b[m+1][2];
	for(i=1;i<=n;i++)
	{
		cin>>a[i].face>>a[i].name;
	}
	for(i=1;i<=m;i++)
	{
		for(j=0;j<2;j++)
		{
			cin>>b[i][j];
		}
	}
	for(i=1;i<=m;i++)
	{
		if (b[i][0]!=a[num].face)
		{
			num=num+b[i][1];
			num=num%n;
		}
		else
		{
			num=num-b[i][1];
			if (num<=0)
			{
				num=num+n;
			}
			num=num%n;
		}
	}
	cout<<a[num].name;
	return 0;
}
