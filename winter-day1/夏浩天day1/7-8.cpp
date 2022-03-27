#include<iostream>
#include<stack>
#include<string.h>
using namespace std;
stack <char> Q;
char s[10001];
int main()
{
    Q.push('#');
    cin >> s;
    int len = strlen(s);
    for (int i = 0; i < len; i++)
    {
        if (s[i] != '[' && s[i] != '(' && s[i] != ']' && s[i] != ')' && s[i] != '{' && s[i] != '}')
            continue;
        if (s[i] == '[' || s[i] == '(' || s[i] == '{')
            Q.push(s[i]);
        else if ((s[i] == ']' && Q.top() == '[') || (s[i] == ')' && Q.top() == '(') || (s[i] == '}' && Q.top() == '{'))
            Q.pop();
        else
            Q.push(s[i]);
    }
    if (Q.top() == '#')
        cout<<"yes"<<endl;
    else
        cout<<"no"<<endl;
    return 0;
}