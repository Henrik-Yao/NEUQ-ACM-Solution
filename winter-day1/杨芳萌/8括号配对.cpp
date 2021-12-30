#include<bits/stdc++.h>
using namespace std;
stack<char> a;
string s;
int main(){
	cin>>s;
	for(int i=0; i<s.length(); i++) {
		if(s[i]=='{'||s[i]=='('||s[i]=='[') a.push(s[i]);
		else {
			char tmp = a.top();
			if(s[i]==')'&&tmp=='(') a.pop();
			if(s[i]==']'&&tmp=='[') a.pop();
			if(s[i]=='}'&&tmp=='{') a.pop();
		}
	}
	if(a.empty()) puts("yes");
	else puts("no");
    return 0;
}
