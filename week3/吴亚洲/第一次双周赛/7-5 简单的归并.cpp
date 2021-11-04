#include<bits/stdc++.h>
using namespace std;
int a[101],b[101],c[201];
int main()
{
	int t;
	cin>>t;
	for(int m=1;m<=t;m++)
	{
		int num;
		cin>>num;
		int k1=num;
		for(int i=1;i<=num;i++)
		cin>>a[i];
		cin>>num;
		int k2=num;
		for(int i=1;i<=num;i++)
		cin>>b[i];
		int i=1,j=1,k=1;
		while(i<=k1&&j<=k2)
		{
			if(a[i]<=b[j])
			c[k++]=a[i++];
			else
			c[k++]=b[j++];
		}
		while(i<=k1)
		c[k++]=a[i++];
		while(j<=k2)
		c[k++]=b[j++];
		for(int i=1;i<k-1;i++)
		cout<<c[i]<<" ";
		cout<<c[k-1];
		cout<<endl;
	}
}
