#include<bits/stdc++.h>
using namespace std;
string s;
int main()
{
	while(getline(cin,s))
	{
		int l=0,r=0;
		int len=s.length();
		for(int i=0;i<len;i++)
		{
			if(s[i]=='(')
			l++;
			else if(s[i]==')')
			{
				if(l)
				l--;
				else
				r++;
			}
		}
		if(l==0&&r==0)
		cout<<"Match"<<endl;
		else
		{
			cout<<l+r<<endl;
			while(r--)
			s='('+s;
			while(l--)
			s=s+')';
			cout<<s<<endl;
		}
	}
}
