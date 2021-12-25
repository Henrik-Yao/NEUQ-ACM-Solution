#include<bits/stdc++.h>
#define ll long long
using namespace std;
string a,b,c;
int main()
{
	string a1="sae";
	string a2="tsaedsae";
	getline(cin,a);
	int len=a.length();
	for(int i=0;i<len;i++)
	{
		if(a[i]=='A')b=b+a1;
		else if(a[i]=='B')b=b+a2;
		else if(a[i]!='#')b=b+a[i];	
	}
	len=b.length();
	for(int i=0;i<len;i++)
	{
		if(b[i]=='(')
		{
			i++;
			char ch=b[i];
			int l=i,r=i;
			while(b[r]!=')')
			r++;
			r--;
			for(int j=r;j>=l+1;j--)
			{
				c=c+ch+b[j];
			}
			c=c+ch;
			i=r+1;
		}
		else c=c+b[i];
	}
	cout<<c;
	return 0;
}
