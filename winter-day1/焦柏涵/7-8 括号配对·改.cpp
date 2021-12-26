#include <bits/stdc++.h>
using namespace std;
stack <char> p;
int main()
{
	string z;
	p.push('$');
	cin>>z;
	int len=z.size();
	for(int i=0;i<len;i++)
	{
		if(z[i]=='('||z[i]=='['||z[i]=='{') p.push(z[i]);
		else if(z[i]==')'&&p.top()=='('||(z[i]==']'&&p.top()=='[')||(z[i]=='}'&&p.top()=='{')) p.pop();
		else continue;
	}
	if(p.top()=='$') cout<<"yes";
	else cout<<"no";
	cout<<endl;
	return 0;
}
