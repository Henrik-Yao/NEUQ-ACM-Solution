#include<bits/stdc++.h>
using namespace std;

int main()
{
	string str;
	char c;
	while(cin>>c)
	{
		if(c=='A'){str+="sae";}
		else if(c=='B'){str+="tsaedsae";}
		else if(c=='(')
		{
			stack<char> st;
			char t;
			cin>>t;
			while(cin>>c)
			{
				if(c==')'){break;}
				else{st.push(c);}
			}
			while(!st.empty())
			{
				str+=t;
				char tt=st.top();
				str+=tt;
				st.pop();
			}
			str+=t;
		}
		else{break;}
	}
	cout<<str;
	return 0;
}
