#include<bits/stdc++.h>
#include<vector>
using namespace std;
vector<char>v;
int main()
{
	string str;
	while(cin>>str)
	{
		v.clear();
		for(int i=0;i<str.length();i++)
		{
			if(v.empty())
			{
				v.push_back(str[i]);
			}
			else if(str[i]==')'&&v.back()=='(')
			{
				v.pop_back();
				continue;	
			}
			else
			{
				v.push_back(str[i]);
			}
		}
		if(v.empty())
		{
			cout<<"Match"<<endl;
			continue;
		}
		cout<<v.size()<<endl;
		for(int i=0;i<v.size();i++)
		{
			if(v[i]==')')
			{
				cout<<"(";
			}
		}	
		cout<<str;
		for(int i=0;i<v.size();i++)
		{
			if(v[i]=='(')
			{
				cout<<")";
			}
		}	
		cout<<endl;
	}
	return 0;
}
