#include <iostream>
#include <cstring>
#include <cstring>
using namespace std;
typedef unsigned long long ULL;
const int N = 10010;
int main() {
    int ans = 0;
    string str0;
    getline(cin, str0);
    int len0 = str0.size();
    string strs[len0 / 2];
    int idx = 0;
    string temp;
    for (int i = 0; i < len0; i++) {
        if (str0[i] >= 'a' && str0[i] <= 'z') {
            temp += str0[i];
        } else if (str0[i] >= 'A' && str0[i] <= 'Z') {
            temp += str0[i] - 'A' + 'a';
        } else if ((str0[i - 1] <= 'z' && str0[i - 1] >= 'a') || (str0[i - 1] <= 'Z' && str0[i - 1] >= 'A')) {
            strs[idx] = temp;
            idx++;
            temp = "";
        }
        if (i == len0 - 1) strs[idx] = temp;
    }
    string pattern;
    getline(cin, pattern);
    for (int i = 0; i < (int)pattern.length(); i++) {
        if (pattern[i] >= 'A' && pattern[i] <= 'Z') pattern[i] = pattern[i] - 'A' + 'a';
    }
    for (int i = 0; i <= idx; i++) {
        for (int j = 0; j < int(strs[i].length() - pattern.length() + 1); j++) {
            if (strs[i].substr(j, pattern.length()) == pattern) {
                ans++;
                break;
            }
        }
    }
    cout << ans;
    return 0;
}

