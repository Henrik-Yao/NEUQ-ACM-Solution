#include <bits/stdc++.h>
using namespace std;
stack<char> stc;
bool check(char ch)
{
    if (ch == '(' || ch == ')' || ch == '[' || ch == ']' || ch == '{' || ch == '}') return true;
    return false;
}
bool check1(char ch)
{
    if (ch == '(' || ch == '[' || ch == '{') return true;
    return false;
}
bool check2(char ch)
{
    if (ch == ')' || ch == ']' || ch == '}') return true;
    return false;
}
bool check3(char left, char right) {
    if ((left == '(' && right == ')') || (left == '[' && right == ']') || (left == '{' && right == '}')) return true;
    return false;
}
int main()
{
    string str;
    getline(cin, str);
    for (int i = 0; i < str.size(); i++) {
        char ch = str[i];
        if (check(ch)) {
            if (check1(ch)) stc.push(ch);
            if (check2(ch)) {
                if (stc.empty()) {
                    cout << "no" << endl;
                    break;
                }
                else {
                    char tmp = stc.top();
                    stc.pop(); // 弹出左括号
                    if (!check3(tmp, ch)) {
                        cout << "no" << endl;
                        break;
                    }
                }
            }
        }
    }
    if (stc.empty()) cout << "yes" << endl;
    else cout << "no" << endl;
    return 0;
}