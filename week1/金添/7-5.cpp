#include <bits/stdc++.h>
using namespace std;
struct ren
{
	int num;
	string name;
};
ren r[1000000];
int main()
{
	int n,m,x,y;
	
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>r[i].num>>r[i].name;
	}
	int k=1;
	for(int j=0;j<m;j++)
	{
		cin>>x>>y;
		if(r[k].num==1)
		{
			if(x==0) 
			k=k+y;			 
			else
			k=k-y;
			
			if(k>n)
			k=k%n;
			else if(k<=0)
			k=k+n;

		}
		else
		{
			if(x==0)
			k=k-y;
			else 
			k=k+y;
			
			if(k>n)
			k=k%n;
			else if(k<=0)
			k=k+n;
		}
	}
	cout<<r[k].name;
	return 0;
} 
