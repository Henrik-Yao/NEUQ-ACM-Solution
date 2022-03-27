#include <bits/stdc++.h>
using namespace std;
int main()
{
    string str;
    while (cin >> str) {
        int l = 0, r = 0;
        for (int i = 0; i < str.size(); i++) {
            if (str[i] == '(') l++; // 单独左括号
            else {
                if (l == 0) r++; // 单独右括号
                else l--;
            }
        }
        if (l == 0 && r == 0) cout << "Match"<< endl;
        else {
            cout << l + r << endl;
            for (int i = 0; i < r; i++) cout << '(';
            cout << str;
            for (int i = 0; i < l; i++) cout << ')';
            cout << endl;
        }
    }
    return 0;
}