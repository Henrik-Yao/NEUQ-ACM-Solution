#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,m,x,y;
	cin>>n>>m;
	int a[n+1]={};
	string name[n+1];
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];//朝向
		cin>>name[i];//名字
	}
	int i=1,f=0;
	while(m--)
	{
		cin>>x>>y;
		f=a[i]+x;
		if(f==1)//逆时针找人
		{
			if(i+y<=n) i=i+y;
			else i=i+y-n;
		}
		else//顺时针找人
		{
			if(i-y>=1) i=i-y;
			else i=n-(y-i);
		}
	}
	cout<<name[i];
    return 0;
}
