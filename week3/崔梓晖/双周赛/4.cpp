#include <bits/stdc++.h>
using namespace std;
int main()
{
	unsigned long long i,j,k,n,ans=0,minn=999999999;
	unsigned long long hn[100];
	while(cin>>n)
	{
	hn[1]=1;
	hn[2]=3;
	for(i=3;i<=n;i++)
	{
		for(j=1;j<i;j++)
		{
			unsigned long long anss=1;
			for(k=1;k<=i-j;k++)
			{
				anss=anss*2;
			}
			ans=hn[j]*2+anss-1;
			minn=min(ans,minn);
		}
	hn[i]=minn;
	minn=999999999;
	ans=0;
	}
	cout<<hn[n]<<endl;
    }
    return 0;
}
