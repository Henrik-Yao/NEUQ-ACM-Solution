#include<bits/stdc++.h>
using namespace std;
vector<char>Q;
int main(){
    string s;
    cin>>s;
    int length=s.length();
    int flag=1;
    for(int i=0;i<length;i++){
    	if(s[i]=='('||s[i]=='['||s[i]=='{')Q.push_back(s[i]);
    	else if(s[i]==')'||s[i]==']'||s[i]=='}'){
    		if(Q.empty()){
    			cout<<"no";
    			return 0;
			}
    		char m=Q.back();
    		Q.pop_back();
    		if(m=='('&&s[i]==')'||m=='['&&s[i]==']'||m=='{'&&s[i]=='}')continue;
    		else {
    			cout<<"no";
    			return 0;
			}
		}
	}
	if(!Q.empty()){
		cout<<"no";
		return 0;
	}
	cout<<"yes";
	return 0;
}
