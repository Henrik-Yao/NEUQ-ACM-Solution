#include<bits/stdc++.h>
using namespace std;
int main(){
	stack<char>z;
	string s;
	cin>>s;
	int cnt=0;
	for(int i=0;i<s.length();i++){
		if(s[i]=='(')z.push(s[i]),cnt++;
		if(s[i]=='[')z.push(s[i]),cnt++;
		if(s[i]=='{')z.push(s[i]),cnt++;
		if(s[i]=='}'&&z.top()=='{')z.pop(),cnt--;
		if(s[i]==']'&&z.top()=='[')z.pop(),cnt--;
		if(s[i]==')'&&z.top()=='(')z.pop(),cnt--;
		
	}
	if(cnt==0)cout<<"yes";
	else cout<<"no";
	return 0;
}
