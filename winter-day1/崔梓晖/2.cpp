#include <bits/stdc++.h>
using namespace std;
vector<char>a;
string s;
int main()
{
	int pos=0;
	int pd=0;
	int num=0;
	getline(cin,s);
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='[')
		{
			pos=0;
		}
		if(s[i]==']')
		{
			pos=num;
		}
		if(s[i]=='{')
		{
			pos--;
		}
		if(s[i]=='}')
		{
			pos++;
		}
		if(s[i]=='-')
		{
			if(pd==1)
			{
				pd=0;
			}
			else if(pd==0)
			{
				pd=1;
			}
		}
		if(s[i]=='=')
		{
			a.erase(a.begin()+pos-1);
			pos--;
			num--;
		}
		if(pd==0)
		{
	    if((s[i]>='a'&&s[i]<='z')||s[i]==' ')
		{
			a.insert(a.begin()+pos,s[i]);
			pos++;
			num++;
		}
	    }
	    if(pd==1)
	    {
		if((s[i]>='a'&&s[i]<='z')||s[i]==' ')
		{
			a.erase(a.begin()+pos);
			num--;
			if(num<0)
			num=0;
			a.insert(a.begin()+pos,s[i]);
			pos++;
			num++;
		}
		}
		if(pos<0)
		pos=0;
		if(pos>num)
		pos=num;
		if(num<0)
		num=0;
	}
	for(int i=0;i<num;i++)
	{
		cout<<a[i];
	}
	return 0;
}


