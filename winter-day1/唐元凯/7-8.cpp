#include<iostream>
#include<string>
#include<stack>
using namespace std;
int main() {
    string s;
    cin >> s;
    int l1 = 0, l2 = 0, l3 = 0;
    stack<char>c;
    bool flag = 1;
    for (auto a : s) {
        if (a == '(') { c.push(a); ++l1; }
        else if (a == '[') { c.push(a); ++l2; }
        else if (a == '{') { c.push(a); ++l3; }
        else if (a == ')')
            if ((--l1) >= 0 && c.top() == '(')c.pop();
            else { flag = 0; break; }
        else if (a == ']')
            if ((--l2) >= 0 && c.top() == '[')c.pop();
            else { flag = 0; break; }
        else if (a == '}')
            if ((--l3) >= 0 && c.top() == '{')c.pop();
            else { flag = 0; break; }
    }
    if (!c.empty())flag = 0;
    flag ? cout << "Yes" << endl : cout << "No" << endl;
}


