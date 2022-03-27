#include<bits/stdc++.h>
using namespace std;
int n,e;
int a[110][110];
int b,c,d,flag,m,sum=100086,sum1=0;
int main()
{
   while(cin>>n>>e)
   { sum=100086;
   memset(a,0x3f,sizeof(a));
   	
	for(int i=0;i<e;i++)
	{
		cin>>b>>c>>d;
		a[b][c]=d;
		a[c][b]=d;
	}
		
	for(int i=0;i<n;i++)
	{
		a[i][i]=0;
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			for(int k=0;k<n;k++)
			{  
				m=a[i][k]+a[k][j];
				a[i][j]=min(m,a[i][j]);
			}
		}
	}
	for(int i=0;i<n;i++)
	{   sum1=0;
		for(int j=0;j<n;j++)
		{  
			sum1=sum1+a[i][j];
		
		}
			
		if(sum1<sum)
		{
			sum=sum1;
			flag=i;
		}
	 } 
	 cout<<flag<<endl;
	
   }

	
	
	
	
} 
