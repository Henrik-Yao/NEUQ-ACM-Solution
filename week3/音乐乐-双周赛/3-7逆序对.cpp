#include<bits/stdc++.h> 
using namespace std;
int a[101],b[101],c[205];

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int n,m,i,j,p=0,k=0,t=0;
		cin>>n;
		for(i=0;i<n;i++)
		cin>>a[i];
		cin>>m;
		for(j=0;i<m;j++)
		cin>>b[j];
		while(p<n&&k<m)
		{
			if(a[p]<=b[k])
			{
				c[t]=a[p];
				p++;
				t++;
			}
			else
			{
				c[t]=b[k];
				k++;
				t++;
			}
		}
		while(p<n)
		{
			c[t]=a[p];
			p++;
			t++;
		}
		while(k<m)
		{
			c[t]=b[k];
			k++;
			t++;
		}
		for(i=0;i<m+n;i++)
		{
			cout<<c[i]<<' ';
		}
	}
	return 0;
}

