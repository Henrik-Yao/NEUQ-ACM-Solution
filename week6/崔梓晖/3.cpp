#include <bits/stdc++.h>
using namespace std;
int main()
{
	string a,b,a1;
	int ans=0;
	getline(cin,a);
	cin>>b;
	for(int i=0;i<a.size();i++)
	{
		if(a[i]>='A'&&a[i]<='Z')
		{
			a[i]=a[i]+32;
		}
		if(a[i]<'a'||a[i]>'z')
		{
			a[i]=' ';
		}
	}
	for(int i=0;i<b.size();i++)
	{
		if(b[i]>='A'&&b[i]<='Z')
		{
			b[i]=b[i]+32;
		}
	}
	a=' '+a+' ';
	for(int i=0;i<a.size();i++)
	{
		if(a[i-1]==' '&&a[i]==' ')
		{
			continue;
		}
		else
		{
			if(a[i]!=0)
			{
				a1=a1+a[i];
			}
			if(a[i]!=' '&&a[i+1]==' ')
			{
				//cout<<a1<<endl;
				int pos=a1.find(b);
				if(pos==-1)
				{
					a1="";
					continue;
				}
				else 
				{
				 ans++;
				 a1="";
			    }
			}
		}
	}
	cout<<ans;
	return 0;
}
