#include<bits/stdc++.h>
using namespace std;
struct d
{
	double v;
	double t;
}d1[100001];

int main()
{
	int n,ta;
	cin>>n>>ta;
	for(int i=0;i<n;i++)
	{
		cin>>d1[i].v>>d1[i].t;
		if(d1[i].t>ta){d1[i].v=d1[i].v-d1[i].t+ta;}	
		else{}	
	}
	for(int i=0;i<n-1;i++)
	{
		for(int j=0;j<n-1-i;j++)
		{
			if(d1[j].v<d1[j+1].v)
			{
				d t=d1[j];
				d1[j]=d1[j+1];
				d1[j+1]=t;
			}
			else{}
		}
		
	}
	

	cout<<d1[0].v;
	return 0;
}
