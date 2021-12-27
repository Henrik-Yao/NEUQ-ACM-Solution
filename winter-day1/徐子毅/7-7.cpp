#include <iostream>
#include <cstring>
#include <stack>
using namespace std;
stack<char> wt;
int main(){
	string str;
	cin >> str;
	for(int i=0;i<str.size();i++){
		if(str[i]=='A') cout << "sae";
		else if(str[i]=='B') cout << "tsaedsae";
		else if(str[i]=='('){
			char ors=str[i+1];
            cout << ors;
			int j;
			for(j=i+2;j<str.size();j++) if(str[j]>='a'&&str[j]<='z'){
				wt.push(str[j]);
			}
			while(!wt.empty()){
				cout << wt.top() << ors;
				wt.pop();
			}
			while(str[i]!=')') i++;
		}else if(str[i]>='a'&&str[i]<='z') cout << str[i];
	}
	cout << endl;
	return 0;
}