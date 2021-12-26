#include<bits/stdc++.h>
using namespace std;
int len,w,y;
stack<int>Q;
int main()
{   Q.push('#');
	string s;
	cin>>s;
	len=s.size();
	for(int i=0;i<len;i++)
	{
		if(s[i]!='['&&s[i]!='{'&&s[i]!='('&&s[i]!=']'&&s[i]!='}'&&s[i]!=')') continue;
		if(s[i]=='['||s[i]=='{'||s[i]=='(') Q.push(s[i]);
		else if((s[i]==']'&&Q.top()=='[')||(s[i]=='}'&&Q.top()=='{')||(s[i]==')'&&Q.top()=='(')) Q.pop();
		else Q.push(s[i]);
	}
	if(Q.top()=='#') cout<<"yes"<<endl;
	else cout<<"no"<<endl;
	return 0;
}
