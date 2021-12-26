#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,m,k,pd[1001],flag=1,t=0;
	cin>>n>>m>>k;
	while(t<n)
	{
		for(int i=1;i<m;i++)
		{
			for(int j=1;;)
			{
				flag--;
				if(flag<=0)
				{
					flag=flag+n;
				}
				if(pd[flag]==1)
				{
					continue;
				}
				else break;
			}
		}
		cout<<flag<<" ";
		t++;
		pd[flag]=1;
		for(int i=1;i<k;i++)
		{
			for(int j=1;;)
			{
				flag++;
				if(flag>n)
				{
					flag=flag-n;
				}
				if(pd[flag]==1)
				{
					continue;
				}
				else break;
			}
		}
		cout<<flag<<" ";
		t++;
		pd[flag]=1;
	}
	return 0;
}
