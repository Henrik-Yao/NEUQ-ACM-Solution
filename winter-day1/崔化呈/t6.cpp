#include<bits/stdc++.h>
using namespace std;
int main()
{
	stack<char> t;
	string s;
	char c;
	while(cin>>c)
	{
		t.push(c);
		s+=c;
	}
	for(int i=0;i<s.size();i++)
	{
		if(s[i]!=t.top()){cout<<"no";return 0;}
		t.pop();
	}
	cout<<"yes";
	return 0;
}
