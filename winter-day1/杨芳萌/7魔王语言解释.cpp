#include<bits/stdc++.h>
using namespace std;
stack<char> a;
string ans="";

void renhua(int i) {
	char tmp = s[i+1];
	i+=2;
	while(s[i]!=')') a.push(s[i]),i++; 
	while(!a.empty()) {
		ans = ans+tmp+a.top();
		a.pop();
	}
	ans += tmp;
} 

int main(){
	getline(cin, s);
	int n = s.length();
	for(int i=0; i<n; i++) {
		if(s[i]=='(') renhua(i);
		else if(s[i]=='A') ans += "sae"; 
		else if(s[i]=='B') ans += "tsaedsae";
		else if(s[i]=='#') break;
	}
	cout<<ans<<endl;
    return 0;
}

