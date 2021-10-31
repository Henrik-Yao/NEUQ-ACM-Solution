#include<bits/stdc++.h>
using namespace std;
int c[105]={};
void f(int a[],int b[],int m,int n)
{
	int i=1,j=1;//指针
	for(int k=1;k<=n+m;k++)
	{
		if(i>m)
		 {
		 	c[k]=b[j];
		 	j++;
		 }
		else if(j>n)
		{
			c[k]=a[i];
			i++;
		}
		else if(a[i]<=b[j])
		{
			c[k]=a[i];
			i++;
		}
		else if(b[j]<a[i])
		{
			c[k]=b[j];
			j++;
		}
	}
	for(int k=1;k<n+m;k++)
	{
		cout<<c[k]<<" ";
	}
	cout<<c[n+m]<<endl;
	return;
}
int main()
{
	int t,m,n;
	cin>>t;
	while(t--)
	{
		cin>>m;
	    int a[m+1];
	    for(int i=1;i<=m;i++)
	  {
		cin>>a[i];
	  }
	  
	    cin>>n;
	    int b[n+1];
	    for(int i=1;i<=n;i++)
	  {
		cin>>b[i];
      }//输入结束！！！
      f(a,b,m,n);
	}
	return 0;	
}
