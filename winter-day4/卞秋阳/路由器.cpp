#include<bits/stdc++.h>
using namespace std;
int n,e,t,y,z;
int a[205][205];
int b,c,d,flag,m,sum=100086,sum1=0;
int main()
{
   while(cin>>n>>e)
   { sum=100086;
   memset(a,0x3f,sizeof(a));
   
	for(int i=0;i<n;i++)
	{
		cin>>b>>c;
		for(int j=1;j<=c;j++)
		{   cin>>t;
			a[b][t]=1;
		    
		}
		
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
	  while(e--){
	  	cin>>y>>z;
	  	if(a[y][z]==1061109567) cout<<"connection impossible"<<endl;
	  	else cout<<a[y][z]<<endl;
	  }
		
}
	
	
   }
