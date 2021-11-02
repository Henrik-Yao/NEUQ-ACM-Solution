#include<bits/stdc++.h>
#include<string>
using namespace std;
int n,b[10000],c[10000],flag[10000]={0};
void range(int t)
{	
	int i;
	char d;
	if(t==n)
	{	
		for(i=0;i<t;i++)
		{
		    d=c[i]+97;
			cout<<d;
		}
		cout<<endl;
		return;
	}
	for(i=0;i<n;i++)
	{
		if(flag[i]==0)
		{
			flag[i]=1;
			c[t]=b[i];
			range(t+1);
			flag[i]=0;
		}
	}
}
int main()
{	
	string a;
	cin>>a;
	n=a.size();
	for(int i=0;i<n;i++)
	{
	    b[i]=a[i]-97;
	}
	sort(b,b+n);
	range(0);
}
