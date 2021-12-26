#include<bits/stdc++.h>
#define ll long long
using namespace std;
string a,s;
int flag,pos;
bool pan(char ch)
{
	if(ch=='{'||ch=='}'||ch=='['||ch==']'||ch=='-'||ch=='=')
		return 1;
	return 0;
}
void doit(char ch)
{
	int len=s.length();
	if(ch=='{' && pos>0)pos--;
	if(ch=='}' && (pos<len))pos++;
	if(ch=='[')pos=0;
	if(ch==']')pos=len;
	if(ch=='-')
	{
		if(flag==0)flag=1;
		else if(flag==1)flag=0;
	}
	if(ch=='=')
	{
		if(len>0 && pos>0)
		{
			s=s.substr(0,pos-1)+s.substr(pos,len);
			pos--;
		}
	}
}
int main()
{
	getline(cin,a);
	int len=a.length();
	for(int i=0;i<len;i++)
	{
		if(pan(a[i]))
		{
			doit(a[i]);
		}
		else
		{
			if(flag==0)
			{
				if(pos==s.length())
				{
					s+=a[i];
				}
				else if(pos==0)
				{
					s=a[i]+s;
				}
				else
				{
				s=s.substr(0,pos)+a[i]+s.substr(pos,s.length());
				}
			}
			if(flag==1)
			{
				if(pos==s.length())
					s=s+a[i];
				else{
					s=s.substr(0,pos)+a[i]+s.substr(pos+1,s.length());
				}
			}
		pos++;
		}
	}
	cout<<s;
	return 0;
}
