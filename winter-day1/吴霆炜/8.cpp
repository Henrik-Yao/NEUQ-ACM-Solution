#include <bits/stdc++.h>
using namespace std;
#define maxn 1000010

stack<char>s;
char transfer(char ch){
    char ans = '\0';
    if(ch == ')') ans = '(';
    if(ch == ']') ans = '[';
    if(ch == '}') ans = '{';
    return ans;
}

int main(){
    string str;
    getline(cin,str);
    int i = 0;
    while(i < str.size()){
        if(str[i] == '(' || str[i] == '[' || str[i] == '{') s.push(str[i]);
        if(str[i] == ')' || str[i] == ']' || str[i] == '}')
        if(transfer(str[i]) == s.top()) s.pop();
        i++;
    }
    if(s.empty())puts("yes");
    else puts("no");
    return 0;
}