#include<iostream>
#include<string>
#include<cstdio>
#include<stack>
using namespace std;
int main() {
    string s;
    while (cin >> s)
    {
        int l1 = 0, l2 = 0;
        stack<char>c;
        bool flag = 1;
        for (auto a : s) {
            if (a == '(') { c.push(a); ++l1; }
            else if (a == ')') {
                if (!l1)l2++;

                if ((l1 - 1) >= 0 && c.top() == '(') { c.pop(); --l1; }
                else { flag = 0; }
            }
        }
        if (flag) cout << "Match" << endl;
        else {
            cout << l1 + l2 << endl;
            s.insert(0, l2, '(');
            s.insert(s.end(), l1, ')');
            cout << s << endl;
        }
    }
}