#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t,n;
	int a[1005]={},f[1005]={};
	cin>>t;
	while(t--)
	{
		int Max=0;
		cin>>n;
		for(int i=0;i<n;i++)
		cin>>a[i];
		memset(f,1,sizeof(f));
		for(int i=0;i<n;i++)
		{
			int _max=0;
			for(int j=0;j<i;j++)
			{
				if(a[j]<a[i])
				_max=max(f[j],_max);
			}
			f[i]=_max+1;
			Max=max(Max,f[i]);
		}
		cout<<Max<<endl;
	}
}
