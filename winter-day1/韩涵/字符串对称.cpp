/*
#include<iostream>
using namespace std;
#define SCALE 128
int main() {
    string s;
    cin >> s;
    int len = s.length();
    int ans1 = 0, ans2 = 0;
    for (int i = 0; i < len; i++) {
        ans1 = ans1 * SCALE + s[i];
        ans2 = ans2 * SCALE + s[len - i - 1];
    }
    if (ans1 == ans2) cout << "yes";
    else cout << "no";

}
*/