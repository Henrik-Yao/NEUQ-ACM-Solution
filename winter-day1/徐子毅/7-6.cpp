#include <iostream>
#include <stack>
#include <cstring>
using namespace std;
stack<char> st;
int main(){
	string str;
	cin >> str;
	int i;
	for(i=0;i<str.size()/2;i++){
		st.push(str[i]);
	}
	// bool issymmetry=true;
	if(str.size()%2!=0) i++;
	for(;i<str.size();i++){
		if(str[i]==st.top()){st.pop();}
		else{cout << "no" << endl;return 0;}
	}
	cout << "yes" << endl;
	return 0;
}