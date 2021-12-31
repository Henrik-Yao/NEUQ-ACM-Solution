#include<bits/stdc++.h>
#define ll long long
#define R register
#define N 10000007
using namespace std;
string read()
{
	int n;
	string s="",x;
	char ch;
	while(cin>>ch)
	{
		if(ch=='[')
		{
			cin>>n;
			x=read();
			while(n--)s+=x;
		}
		else if(ch==']')
			return s;
		else s+=ch;
	}
}
int main()
{
	cout<<read();
	return 0;
}
