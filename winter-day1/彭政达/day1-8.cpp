#include <bits/stdc++.h>
using namespace std;
int main(){
    stack<char> a;
    string x;
    int flag=1;
    cin>>x;
    for(int i=0;i<x.size();i++){
        if(x[i]=='[' || x[i]=='(' || x[i]=='{') a.push(x[i]);
        else if(x[i]==']' && a.top()=='['){
            a.pop();continue;
        }
        else if(x[i]=='}' && a.top()=='{'){
            a.pop();continue;
        }
        else if(x[i]==')' && a.top()=='('){
            a.pop();continue;
        }
        else if(x[i]==']' && a.top()!='['){
            flag=0;break;
        }
        else if(x[i]=='}' && a.top()!='{'){
            flag=0;break;
        }
        else if(x[i]==')' && a.top()!='('){
            flag=0;break;
        }
    }
    if(flag && a.empty()) cout<<"yes"<<endl;
    else cout<<"no"<<endl;
}
