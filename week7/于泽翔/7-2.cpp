#include <bits/stdc++.h>
using namespace std;


string unf(void)
{
	string s, s1;
	char c;
	int n;
	
	while(cin>>c)
	{
		if(c=='[')
		{
			cin>>n;
			s1=unf();
			while(n--)
				s+=s1;
		}
		else if(c==']')
			return s;
		else
			s+=c;
	}
}

int main(void)
{
    cout<<unf();
    
	return 0;
}
