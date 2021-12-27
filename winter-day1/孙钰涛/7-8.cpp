#include<iostream>
#include<cstring>
#include<stack>
using namespace std;
stack<char>z;
int main()
{
	char x;
	while(cin>>x)
	{
		if(x=='(' || x=='[' || x=='{') z.push(x);
		else if((x==')'&&z.top()=='(')||(x==']'&&z.top()=='[')||(x=='}'&&z.top()=='{')) z.pop();
	} 
	if(z.empty()) cout<<"yes";
	else cout<<"no";
	return 0;
}