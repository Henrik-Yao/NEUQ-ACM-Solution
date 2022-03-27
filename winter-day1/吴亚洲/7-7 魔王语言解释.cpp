#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	getline(cin,s);
	int len=s.length();
	for(int i=0;i<len;i++)
	{
		if(s[i]=='A')
		cout<<"sae";
		else if(s[i]=='B')
		cout<<"tsaedsae";
		else if(s[i]=='(')
		{
			string t;
			int y=i;
			char x=s[i+1];
			while(s[i]!=')')
			i++;
			for(int j=i;j>=y+2;j--)
			cout<<x<<s[j];
		}
	}
}
