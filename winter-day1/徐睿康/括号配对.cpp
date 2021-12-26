#include<bits/stdc++.h>
using namespace std;
string s;
int sta[10000010],top=0,flag=0,len;
int main(){
	cin>>s;
	len=s.length();
	for(int i=0;i<len;i++){
		if(s[i]=='(')sta[++top]=1;
		if(s[i]=='[')sta[++top]=2;
		if(s[i]=='{')sta[++top]=3;
		if(s[i]==')'){
			if(sta[top]==1)top--;
			else flag=1;
		}
		if(s[i]==']'){
			if(sta[top]==2)top--;
			else flag=1;
		}
		if(s[i]=='}'){
			if(sta[top]==3)top--;
			else flag=1;
		}
	}
	if(top==0&&flag==0)cout<<"yes";
	else cout<<"no";
	return 0;
}
