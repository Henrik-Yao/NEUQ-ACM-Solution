#include<bits/stdc++.h>
using namespace std;
string s;
int sum;
int main()
{
	getline(cin,s);
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
	sum=sum+l+r;
	l=0,r=0;
	for(int i=0;i<len;i++)
	{
		if(s[i]=='[')
		l++;
		else if(s[i]==']')
		{
			if(l)
			l--;
			else
			r++;
		}
	}
	sum=sum+l+r;
	l=0,r=0;
	for(int i=0;i<len;i++)
	{
		if(s[i]=='{')
		l++;
		else if(s[i]=='}')
		{
			if(l)
			l--;
			else
			r++;
		}
	}
	sum=sum+l+r;
	if(sum)
	cout<<"no";
	else
	cout<<"yes";
}
