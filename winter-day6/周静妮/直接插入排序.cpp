#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,i,j,k,t;
	int a[101];
	while(cin>>n)
	{
		for(i=0;i<n;i++)	cin>>a[i];
		for(i=1;i<n;i++)
		{		
			t=a[i];
			for(j=i-1;j>=0;j--)
			if(a[j]>t)
			{
				a[j+1]=a[j];
				a[j]=t;
			}
			for(k=0;k<n;k++)
			{
				cout<<a[k];
				if(k==n-1)	cout<<endl;
				else cout<<' ';
			}
			
		}			
	}
	return 0;
}
