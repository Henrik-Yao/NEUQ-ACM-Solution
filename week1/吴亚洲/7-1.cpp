#include<bits/stdc++.h>
using namespace std;
int main()
{
	string a,b;
	int n,judge=0;
	int c[100]={0};
	cin>>n;
	cin>>a;
	for(int i=1;i<=n;i++)
	{
		cin>>b;
		for(int j=0;j<a.length();j++)
		{
			if(a[j]==b[0])
			{
				judge=0;
				for(int m=j;m<j+b.length();m++)
				{
					if(a[m]!=b[m-j])
					judge=1;	
				}
				if(judge==0)
				c[i]++;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		cout<<c[i]<<endl;
	}
	return 0;
}
