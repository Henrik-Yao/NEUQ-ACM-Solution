#include <bits/stdc++.h>
using namespace std;
stack <char> str;
int main()
{
	string s;
	cin>>s;
	str.push('$');
	int len=s.size(),i;
	for(i=0;i<len/2;i++)
	{
		str.push(s[i]);
	}
	if(len%2==1) i++;
	for(;i<len;i++)
	{
		if(str.top()!=s[i])
		{
			cout<<"no";
			break;
		}
		else str.pop();
	}
	if(str.top()=='$') cout<<"yes";
	return 0; 
}
