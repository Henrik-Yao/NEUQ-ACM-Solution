#include <iostream>
#include <stack>
#include <cstring>
using namespace std;
stack<char> small;
stack<char> medium;
stack<char> big;
using namespace std;
int main(){
	string str;
	cin >>str;
	for(int i=0;i<str.size();i++){
		if(str[i]=='(') small.push('(');
		if(str[i]=='[') medium.push('[');
		if(str[i]=='{') big.push('{');
		if(str[i]==')') if(small.empty()){cout << "no" << endl;return 0;} else small.pop();
		if(str[i]==']') if(medium.empty()){cout << "no" << endl;return 0;} else medium.pop();
		if(str[i]=='}') if(big.empty()){cout << "no" << endl;return 0;} else big.pop();
	}
	if(!small.empty()||!medium.empty()||!big.empty()) {cout << "no" << endl;return 0;}
	cout << "yes" << endl;
	return 0;
}