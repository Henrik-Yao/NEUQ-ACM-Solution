#include <bits/stdc++.h>
using namespace std;
int sta[1001],en[1001];
void change(int a)
{
	int c=sta[a];
	sta[a]=sta[a+1];
	sta[a+1]=c;
	c=en[a];
	en[a]=en[a+1];
	en[a+1]=c;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;cin>>n;
		for(int i=0;i<n;i++)
		{
			cin>>sta[i]>>en[i];
		}
		for(int i=0;i<n;i++)
			for(int j=0;j<n-i-1;j++)
			{
				if(en[j]>en[j+1])
				{
					change(j);
				}
			}
		int sum=1,tim=en[0];
		for(int i=1;i<n;i++)
		{
			if(sta[i]>=tim)
			{
				sum++;tim=en[i];
			}
		}
		cout<<n-sum<<endl;
	}
	return 0;
}
