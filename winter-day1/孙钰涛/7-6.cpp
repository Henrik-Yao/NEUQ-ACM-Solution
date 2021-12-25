#include<iostream>
#include<cstring>
#include<stack>
using namespace std;
stack<char>z;
int main()
{
	char x;
	string str1="",str2="";
	while(cin>>x)
	{
		str1=str1+x;
		z.push(x);	
	} 
	while(!z.empty())
	{
		str2=str2+z.top();
		z.pop();
	}
	if(str1==str2) cout<<"yes";
	else cout<<"no";
	return 0;
}