#include <bits/stdc++.h>
using namespace std;
int main()
{
	string a,b;
	string c[12345];
	int i,j,lena,lenb,n=0,m=0;
	bool flag=1;
	getline(cin,a);
	getline(cin,b);
	lena=a.length();
	lenb=b.length();
	for(i=0;i<lenb;i++)
	{
		if(b[i]<='Z' && b[i]>='A') b[i]=b[i]+'a'-'A';
	}
	for(i=0;i<lena;i++)
	{
		if((a[i]<='z' && a[i]>='a') || (a[i]>='A' && a[i]<='Z')) 
		{
			if(flag)
			{
				m++;
				flag=0;
			}
			if(a[i]<='Z' && a[i]>='A') a[i]=a[i]+'a'-'A';
			c[m]+=a[i];
		}
		else 	if(!flag) flag=1;
	}
	for(i=0;i<=m;i++)		if(c[i].find(b)!=-1) n++;
	cout<<n;
	return 0;
}
