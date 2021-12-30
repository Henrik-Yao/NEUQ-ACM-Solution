#include<bits/stdc++.h>
using namespace std;
string s;
int main(){
	while(getline(cin,s)) {
		int n = s.length();
		int head=0, tag=0;
		for(int i=0; i<n; i++) {
			if(s[i]=='(') tag++;
			else tag--;
			if(tag<0) tag=0, head++;
		}
		if(head==0&&tag==0) { cout<<"Match"<<endl; continue; }
		cout<<head+tag<<endl;
		while(head--) cout<<'(';
		cout<<s;
		while(tag--) cout<<')';
		cout<<endl;
	}
    return 0;
}

