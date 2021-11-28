#include<bits/stdc++.h>
using namespace std;
int n;

string jieya()
{
	string a="",b;
	char c;
	while (cin>>c)
	{
		if (c=='[')
		{
			cin>>n;
			b=jieya();
			while (n--)
                a+=b;
		}
		else
		{
			if (c==']')
                return a;
		    else
                a+=c;
		}
	}
}

int main()
{
	cout<<jieya();
	return 0;
}
