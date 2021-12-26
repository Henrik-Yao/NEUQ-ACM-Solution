#include <bits/stdc++.h>
using namespace std;
int main(){
int l,flag=0;
char s[100000];
stack<char>sq;
cin>>s;
l=strlen(s);
for(int i=0;i<l;i++){
	if(s[i]=='('||s[i]=='{'||s[i]=='[')
	sq.push(s[i]);
	if(s[i]==']'){
		if(sq.top()!='['){
			flag=1;break;
		}
		else sq.pop();
	}
	if(s[i]==')'){
		if(sq.top()!='('){
			flag=1;break;
		}
		else sq.pop();
	}
	if(s[i]=='}'){
		if(sq.top()!='{'){
			flag=1;break;
		}
		else sq.pop();
	}
}
if(!sq.empty())
flag=1;
if(flag==1) cout<<"no\n";
else cout<<"yes\n";
return 0;

}
