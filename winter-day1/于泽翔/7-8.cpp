#include <bits/stdc++.h>
using namespace std;
char st[999];
int l_st=0;

int main(void)
{
	char ch;
	while(cin>>ch)
	{
		if(ch=='('||ch=='['||ch=='{')
			st[++l_st]=ch;

		else if(ch==')')
			if(st[l_st]=='(')
				l_st--;
			else
			{
				cout<<"no";
				return 0;
			}
		else if(ch==']')
			if(st[l_st]=='[')
				l_st--;
			else
			{
				cout<<"no";
				return 0;
			}
		else if(ch=='}')
			if(st[l_st]=='{')
				l_st--;
			else
			{
				cout<<"no";
				return 0;
			}
		else
			continue;
	}
	if(l_st==0)
		cout<<"yes";
	else
		cout<<"no";
	
	return 0;
}