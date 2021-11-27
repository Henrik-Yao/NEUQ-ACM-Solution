#include <bits/stdc++.h>
using namespace std;
string solve() {
    string str = "", s1;
    int n;
    char c;
    while (cin >> c) 
    {
        if (c == '[') 
        {
            cin >> n;
            s1 = solve();
            while (n--)
            {
                str += s1;
            }
        }
        else
        {
            if (c == ']')
            {
                return str;
            }
            else str += c;
        }
    }
}


int main() {
    cout << solve();
    return 0;
}