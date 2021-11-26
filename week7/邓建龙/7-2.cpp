#include <bits/stdc++.h>
using namespace std;
string func() {
    string s = "", s1;
    int n;
    char ch;
    while (cin >> ch) {
        if (ch == '[') {
            cin >> n;
            s1 = func();
            while (n--) s += s1;
        } else {
            if (ch == ']') return s;
            else s += ch;
        }
    }
}
int main() {
    cout << func();
    return 0;
}