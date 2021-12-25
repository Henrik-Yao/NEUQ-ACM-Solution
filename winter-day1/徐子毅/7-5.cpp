#include <iostream>
#include <stack>
#include <cstring>
using namespace std;
stack<char> st;
int main(){
	string str;
	while(cin>>str){
		int lnum=0;
		int rnum=0;
		for(int i=0;i<str.size();i++){
			if(str[i]=='(') st.push(str[i]);
			if(str[i]==')'){
				if(st.empty()) lnum++;
				else st.pop();
			}
		}
		while(!st.empty()){rnum++;st.pop();}
		if(st.empty()&&lnum==0&&rnum==0) cout << "Match" << endl;
		else{
			cout << rnum+lnum << endl;
			for(int i=1;i<=lnum;i++) cout << '(';
			cout << str;
			for(int i=1;i<=rnum;i++) cout << ')';
			cout << endl;
		}
	}
	return 0;
}