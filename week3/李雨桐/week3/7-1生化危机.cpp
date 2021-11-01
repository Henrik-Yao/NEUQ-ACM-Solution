#include <bits/stdc++.h>
using namespace std;
struct ma
{
	int a[100][100];
	int num1,num2;
};

int main()
{
	int n;
	int safe[100];
	ma MAP;

	cin>>MAP.num1>>n>>MAP.num2;

	for(int i=0;i<n;i++)
	{
		cin>>safe[i];
	}
	for(int i=0;i<MAP.num1;i++)
	{
		for(int j=0;j<MAP.num1;j++)
		{
			MAP.a[i][j]=0;
		}
	}
	for(int i=0;i<MAP.num2;i++)
	{
		int x,y;
		cin>>x>>y;
		MAP.a[x][y]=1;
		MAP.a[y][x]=1;
	}
	int temp,des,flag1=0;
	cin>>temp>>des;
	for(int i=0;i<n;i++)
	{
		if(des == safe[i])
		{
			flag1 = 1;
			break;
		}
	}

	if(MAP.a[temp][des]==1)
	{
		if(flag1 == 1)
		cout<<"The city "<<des<<" can arrive safely!";
		else
			cout<<"The city "<<des<<" is not safe!";

	}
	else
	{
		if(flag1 == 1)
		cout<<"The city "<<des<<" can not arrive safely!";
		else
            cout<<"The city "<<des<<" is not safe!";
	}

	return 0;
}
