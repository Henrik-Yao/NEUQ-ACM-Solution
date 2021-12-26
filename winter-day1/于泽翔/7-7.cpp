#include<bits/stdc++.h>
using namespace std;

int main()
{
	int l=0, r=0;
	string str;
	cin>>str;
	for(int i=0; i<str.size(); i++)
	{
		if(str[i]=='(')
			l=i;
		else if(str[i]==')')
			r=i;
	}
	for(int i=0; i<str.size(); i++)
	{
		if(str[i]=='A')
			cout<<"sea";
		else if(str[i]=='B')
			cout<<"tsaedsae";
		
		else if(str[i]=='(')
		{
			cout<<str[i+1];
			for(int j=r-1; j>=l+2; j--)
				cout<<str[j]<<str[i+1];
			i=r;
		}
		else if(str[i]=='#')
			break;
	}
	
	
	return 0;
}