#include<bits/stdc++.h>
using namespace std;
int main()
{
	stack<char> t;
	char c;
	while(cin>>c)
	{
		if(c=='('||c=='['||c=='{'){t.push(c);}
		else if(c==')'||c==']'||c=='}')
		{
			t.pop();
		}
		else{}
	}
	if(t.empty()){cout<<"yes";}
	else{cout<<"no";}
	return 0;
}
