#include<iostream>
using namespace std;
int main()
{
	int n,i,j,f[1001]={0};
	cin>>n;
	f[1]=1;
	f[2]=2;
	f[3]=2;
	for(i=4;i<=n;i++)
	{
		for(j=1;j<=i/2;j++)
		{
			if (i%j==0)
			{
				f[i]=f[i]+f[j];
			}
		}
		f[i]=f[i]+1;
	}
	cout<<f[n];
	return 0;
}
