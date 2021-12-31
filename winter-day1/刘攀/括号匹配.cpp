#include<bits/stdc++.h>
using namespace std;
int main(){
	string str;
	getline(cin,str);
	int flag=0;
	stack <char> s;
	char topstr;
	for(int i=0;i<str.size();i++){
		if(str[i]=='{'||str[i]=='['||str[i]=='('){
			s.push(str[i]);
		}
		if(str[i]=='}'||str[i]==']'||str[i]==')'){
			if(s.empty()){
				flag=1;
				break;
			}
			else{
			topstr=s.top();
			if((topstr=='('&&str[i]==')')||(topstr=='{'&&str[i]=='}')||(topstr=='['&&str[i]==']'))
		s.pop();
		else {
			flag=1;
			break;
		}
		}
		}
	} 
	if(s.empty()&&flag==0){
		cout<<"yes"<<endl;
	}
	else cout<<"no"<<endl;
}
