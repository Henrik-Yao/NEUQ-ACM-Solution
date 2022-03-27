#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t,sum=0,max[1001]={0};
	cin>>t;
	while(t--)
	{
		int n,a[1001],f[1001]={1};
		cin>>n;
		for(int i=0;i<n;i++)
		{
			cin>>a[i];f[i]=1;
			for(int j=0;j<i;j++)
			{
				if(a[i]>a[j]&&f[i]<f[j]+1) f[i]=f[j]+1;
			}
			if(f[i]>max[sum]) max[sum]=f[i];
		}
		sum++;
	}
	for(int i=0;i<sum-1;i++) cout<<max[i]<<endl<<endl;
	cout<<max[sum-1];
	return 0;
}
