#include<bits/stdc++.h>
using namespace std;
stack<int>st2;

string f(string s)
{
	string temp;
	if(!st2.size())
	return s;
	else
	{
		for(int i=1;i<=st2.top();i++)
		{
			temp+=s;
		}
		s=temp;
		st2.pop();
	}
}

int main()
{
	string s;
	int i;
	getline(cin,s);
	int num=0;
	for(i=0;i<s.size();i++)
	{
		int cnt;
		if(s[i]=='[')
		{
			num++;
			cnt=s[i+1]-'0';
			if(s[i+2]>='0'&&s[i+2]<='9')
			{
				cnt*=10;
				cnt+=s[i+2]-'0';
			}
			st2.push(cnt);
			string
			int j=i+2;
			if(s[j]>='0'&&s[j]<='9')
			j++;
			while()
			cout<<f(str);
		}
		if(s[i]==']')
		num--;
		if(!num)
		cout<<s[i];
	}
	return 0;
}
