#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
vector<char>z;
int main()
{
	string str;
	while(cin>>str)
	{
		z.clear();
		for(int i=0;i<str.size();i++)
		{
			if(z.empty()) z.push_back(str[i]);
			else if(str[i]==')' && z.back()=='(')
			{
				z.pop_back();
				continue;	
			}
			else z.push_back(str[i]);
		}
		if(z.empty())
		{
			cout<<"Match\n";
			continue;
		}
		cout<<z.size()<<"\n";
		for(int i=0;i<z.size();i++)
			if(z[i]==')') cout<<"(";
		cout<<str;
		for(int i=0;i<z.size();i++)
			if(z[i]=='(') cout<<")";
		cout<<"\n";
	}
	return 0;
}