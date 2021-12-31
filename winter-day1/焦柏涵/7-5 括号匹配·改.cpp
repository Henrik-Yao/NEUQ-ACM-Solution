#include <bits/stdc++.h>
using namespace std;
stack <char> p;
int main()
{
	string z;
	while(1)
	{
		cin>>z;
		p.push('$');
		int len=z.size(),l=0,r=0;
		for(int i=0;i<len;i++)
		{
			if(z[i]=='(')
			{
				p.push(z[i]);
				l++;
			}
			else
			{
				if(p.top()!='(') r++;
				else {
					p.pop();l--;
				}
			}
		}
		if(l==0&&r==0) cout<<"Match";
		else
		{
			cout<<l+r<<endl;
			for(int i=0;i<l;i++) cout<<"(";
			cout<<z;
			for(int i=0;i<r;i++) cout<<")";
		}
		cout<<endl;
	}
	return 0;
}
