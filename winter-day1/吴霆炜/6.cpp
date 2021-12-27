#include <bits/stdc++.h>
using namespace std;

bool flag = true;
stack<char>s,s_reverse;
int main(){
    string str;
    getline(cin,str);
    for(int i = 0;i < str.size();i++) s.push(str[i]);
    for(int i = str.size() - 1;i >= 0;i--) s_reverse.push(str[i]);
    while(!s.empty()){
        if(s.top() != s_reverse.top()){
            flag = false;
            break;
        }
        s.pop(),s_reverse.pop();
    }
    if(flag)puts("yes");
    else puts("no");
    return 0;
}