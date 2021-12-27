#include<bits/stdc++.h>
using namespace std;
stack<char>st;

int main()
{
	string s;
	int i;
	cin>>s;
	//cout<<s<<endl;
	char c;
	for(i=0;i<s.size();i++)
	{
		c=s[i];
		if(c=='['||c=='(')
			st.push(c);
		if(c==']')
		{
			//cout<<st.top()<<endl;
			if(st.top()=='[')
			{
				st.pop();
			}
			else
			{
				cout<<"no"<<endl;
				return 0;
			}
		}
		if(c==')')
		{
			//cout<<st.top()<<endl;
			if(st.top()=='(')
			{
				st.pop();
			}
			else
			{
				cout<<"no"<<endl;
				return 0;
			}
		}
	}
	if(st.size())
		cout<<"no";
    else
        cout<<"yes";
	return 0;
}
