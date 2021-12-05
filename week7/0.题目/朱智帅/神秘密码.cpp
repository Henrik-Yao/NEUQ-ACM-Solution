#include<bits/stdc++.h>
using namespace std;
string read()
{
	int n;
	string s="",s1;
	char c;
	while (cin>>c)//一直读入字符，直到Ctrl+z
	{
		if (c=='[')
		{
			cin>>n;//读入D
			s1=read();//读入X
			while (n--) s+=s1;//重复D次X
		}
		else 
		{
			if (c==']') return s;
		    else s+=c;
		}
	}
}
int main()
{
	cout<<read(); 
	return 0;
}