#include <bits/stdc++.h>
using namespace std;

int main()
{
	int m,n,i,j,t,k,s=0,sum;
	int a[100],b[100];
	cin>>m>>n;
	for(i=0;i<m;i++)	
	{
		cin>>a[i];
		if(i) b[i]=a[i]-a[i-1];
	}
	for(i=1;i<=n;i++)
	{
		t=b[i];
		k=i;
		for(j=i;j<m;j++)
		{
			if(b[j]<t)
			{
				t=b[j];
				k=j;
			}
		}
		b[k]=b[i];
		b[i]=t;
		s+=t;
	}
	sum=a[m-1]-a[0];
	cout<<(sum-s+1);
	return 0;	 
}
