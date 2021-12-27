#include<iostream>
#include<string>
#include<stack>
using namespace std;
int main() {
    string s;
    cin >> s;
    stack<char>c;
    bool flag = 1;
    for (size_t i = 0, length = s.length() / 2; i < length; i++)
    {
        c.push(s[i]);
    }
    for (size_t i = (s.length() + 1) / 2, length = s.length(); i < length; i++)
    {
        if (c.top() == s[i])c.pop();
        else {
            flag = 0;
            break;
        }
    }
    flag ? cout << "yes" << endl : cout << "no" << endl;
}