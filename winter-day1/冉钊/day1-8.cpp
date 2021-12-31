#include<bits/stdc++.h>
using namespace std;
int main(){
    stack<char>exa;
    string s;
    cin>>s;
    for(int i=0;i<=s.size();i++){
        if(s[i]=='('||s[i]=='{'||s[i]=='[')
        exa.push(s[i]);
        else if(s[i]==')'){
            char a=exa.top();
            if(a!='(') break;
            exa.pop();
        }
        else if(s[i]==']'){
            char a=exa.top();
            if(a!='[') break;
            exa.pop();
        }
        else if(s[i]=='}'){
            char a=exa.top();
            if(a!='{') break;
            exa.pop();
        }
    }
    if(!exa.empty())cout<<"no";
    else cout<<"yes";
    return 0;
}