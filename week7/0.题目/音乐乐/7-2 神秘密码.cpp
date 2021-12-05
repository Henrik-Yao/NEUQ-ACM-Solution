#include<bits/stdc++.h>
using namespace std;

string read()
{
	int n;
	string s="",str;
	char c;
	while(cin>>c)
	{
		if(c=='[')
		{
			cin>>n;
			str=read();
			while(n--)
			s+=str;
		}
		else if(c==']')
		return s;
		else
		s+=c;
	}
} 

int main()
{
	cout<<read();
	return 0;
}
