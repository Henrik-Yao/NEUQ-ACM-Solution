#include<iostream>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int m,n,i,j=0,k=0;
		cin>>m;
		int a[m];
        for(i=0;i<m;i++)
		{
			cin>>a[i];
		}	
		cin>>n;
		int b[n],c[n+m];
		for(i=0;i<n;i++)
		{
			cin>>b[i];
		}
		i=0;
		while(j<m&&k<n)
		{
			if(a[j]<b[k])
			{
				c[i]=a[j];
				j++;
				i++;
			}
			else
			{
				c[i]=b[k];
				k++;
				i++;
			}
		}
		while(j<m)
		{
			c[i]=a[j];
			j++;
			i++;
		}
		while(k<n)
		{
			c[i]=b[k];
			k++;
			i++;
		}
		for(i=0;i<n+m-1;i++)
		{
			cout<<c[i]<<" "; 
		}
		cout<<c[n+m-1]<<endl;
	}
	return 0;
} 
