#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,jud[21]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},ju,a,b;
	cin>>n;
	char c[50001],d[21][21];
	cin>>c;
	for(int i=0;i<n;i++)
	{
		cin>>d[i];
	}
	for(int i=0;i<n;i++)
	{
		a=strlen(c);
		for(int j=0;j<a;j++)
		{
			if(c[j]==d[i][0])
			{
				ju=0;
				b=strlen(d[i]);
				for(int k=1;k<b;k++)
				{
					if(c[j+k]==d[i][k])
					continue;
					else
					{
						ju=1;
						break;
					}
				}
				if(ju==0) 
				{
					jud[i]++;
				}
			}
			
		}
	}
	for(int i=0;i<n;i++)
	{
		cout<<jud[i];
		if(i!=n-1) cout<<endl;
	}
	return 0;
}