#include<bits/stdc++.h>
using namespace std;
int main()
{
	string str,s;
	char ch;
	while(cin>>ch)
	{
		if(ch=='#')
		{
			break;
		}
		else if(ch>='a'&&ch<='z')
		{
			str+=ch;
		}
		else if(ch=='A')
		{
			str=str+"sae";
		}
		else if(ch=='B')
		{
			str=str+"tsaedsae";
		}
		else if(ch=='(')
		{
			while(cin>>ch)
			{
				if(ch==')')
				{
					break;
				}
				s+=ch;
			}
			for(int i=s.length()-1;i>0;i--)
			{
				str=str+s[0]+s[i];
			}
			str+=s[0];
		}	
	}
	cout<<str<<endl;
	return 0;
}
