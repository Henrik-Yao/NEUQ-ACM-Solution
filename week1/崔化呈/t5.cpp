#include<bits/stdc++.h>
using namespace std;
struct s
{
	int f;
	char name[100];
}s1[100001];

int main()
{
	int n,m;
	cin>>n>>m;
	
	for(int i=0;i<n;i++)
	{
		cin>>s1[i].f>>s1[i].name;
	}
	int p[100001],r[100001];
	for(int i=0;i<m;i++)
	{
		cin>>p[i]>>r[i];
	}
	int t=0;
	for(int i=0;i<m;i++)
	{
		
		if(s1[t].f==0)
		{
			if(p[i]==0)
			{
				t-=r[i];
			}
			else
			{
				t+=r[i];
			}
		}
		else
		{
			if(p[i]==0)
						{
							t+=r[i];
						}
						else
						{
							t-=r[i];
						}
		}
        t%=n;
		if(t<0){t=n+t;}
		else{}
	}
	cout<<s1[t].name;
	return 0;
}
