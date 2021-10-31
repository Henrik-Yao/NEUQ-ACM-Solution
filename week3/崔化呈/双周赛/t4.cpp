#include<bits/stdc++.h>
using namespace std;
int n;
unsigned long long three[70],four[70];

int main()
{
	three[1]=1;
	memset(four,0x7fffffff,sizeof(four));
    four[1]=1;
			for(int i=2;i<70;i++)
			{
				three[i]=2*three[i-1]+1;
			}
			for(int i=2;i<70;i++)
			{
				for(int j=1;j<i;j++)
				{
					four[i]=min(four[i],four[j]+four[j]+three[i-j]);
				}
			}
	while(cin>>n)
	{
		
		cout<<four[n]<<endl;
	}
	return 0;
}
