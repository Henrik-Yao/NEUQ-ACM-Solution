#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long sum;
	int n;
	long long a[65],b[33];
	memset(a,0x3f,sizeof(a));
	memset(b,0x3f,sizeof(b));
	b[1]=1;
	for(int i=2;i<=32;i++)
	{
		b[i]=b[i-1]*2+1;
	}
	while(~scanf("%d",&n))
	{
		
		a[0]=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<i;j++)
			{
				if(i-j>32) j+=i-j-32;
				a[i]=min(a[i],a[j]*2+b[i-j]);
			}
			
		}
		cout<<a[n]<<'\n';
	}
	return 0;
 } 
