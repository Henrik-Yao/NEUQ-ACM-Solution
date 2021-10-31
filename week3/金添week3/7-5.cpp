#include <bits/stdc++.h>
using namespace std;
int a[100000],b[100000],c[100000];
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		memset(a,0,100000);
		memset(b,0,100000);
		memset(c,0,100000);
		int m,n,rempa=0,rempb=0;
		cin>>m;
		for(int j=1;j<=m;j++)
		{
			cin>>a[j];
			rempa++;
		}	
		cin>>n;
		for(int s=1;s<=n;s++)
		{
			cin>>b[s];
			rempb++;
		}
		//¹é²¢¿ªÊ¼£¡
		int x=1,y=1,z=1;
		while((x<=rempa)&&(y<=rempb))
		{
			if(a[x]<b[y])
			c[z++]=a[x++];
			else
			c[z++]=b[y++];
		}
		while(x<=rempa)
		{
			c[z++]=a[x++];
		}
		while(y<=rempb)
		{
			c[z++]=b[y++];
		}
		for(int i=1;i<=(m+n);i++)
		if(i!=m+n) 
		cout<<c[i]<<" "; 
	    else
		cout<<c[i]<<endl;
	}
	return 0;
}
