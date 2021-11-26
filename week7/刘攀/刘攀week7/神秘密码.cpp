#include<bits/stdc++.h>
using namespace std;
string f(){
	string s;
	string x;
	char c;
	int d;
	while(cin>>c){
		if(c=='['){
			cin>>d;
			x=f();
			while(d--){
				s+=x;
			}
		}
		else if(c==']'){
			return s;
		}
		else s+=c;
	}
	return s;
}
int main(){
	cout<<f();
}
