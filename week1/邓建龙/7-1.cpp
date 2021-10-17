#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int res[n];
    for (int i = 0; i < n; i++) {
        string chs;
        cin >> chs;
        int total = 0;
        for (int j = 0; j < s.length(); j++) {
            int is = 1;
            for (int k = 0; k < chs.length(); k++) {
                if (s[j+k] != chs[k]) {
                    is = 0;
                }
            }
            if (is == 1) {
                total++;
            }
        }
        res[i] = total;
    }
    for (int i = 0; i < n; i++) {
        i != n - 1 ? cout << res[i] << endl : cout << res[i];
    }
    return 0;
}

