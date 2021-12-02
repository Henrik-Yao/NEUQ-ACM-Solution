#include<bits/stdc++.h>
using namespace std;
struct Time
{
	int start,end;
};
int main()
{
	Time p[10000];
	int t,n;
	cin>>t;
	while(t--)
	{
		int i,j,k,count=1;
		cin>>n;
		for(i=0;i<n;i++)
		{
			cin>>p[i].start>>p[i].end;
		}
		for(i=1;i<n;i++)
		{
			for(j=0;j<n-i;j++)
			{
				if(p[j].end>p[j+1].end)
				{
					swap(p[j],p[j+1]);
				}
			}
		}
		for(i=0,k=1;k<n;)
		{
		    if(p[i].end<=p[k].start)
			{
				i=k;
				count++;
			}
			else
			{
				k++;
			}
		}
		cout<<n-count<<endl;
	}
	return 0;
}
