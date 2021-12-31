/*
#include<iostream>
using namespace std;

int longest[1005] = { 0 };
int num[1005] = { 0 };

int main() {
    int t;
    cin >> t;
    int m = t;
    while (m--) {
        if (m != t - 1) cout << endl;
        int len;
        int ans = 1;
        cin >> len;
        num[0] = -1;
        for (int i = 1; i <= len; i++) cin >> num[i];
        for (int i = 1; i <= len; i++) {
            for (int j = 0; j < i; j++) {
                if (num[i] > num[j])
                    longest[i] = longest[i] > longest[j] + 1 ? longest[i] : longest[j] + 1;
            }
            ans = ans > longest[i] ? ans : longest[i];
        }
        cout << ans << endl;
        for (int i = 1; i <= len; i++) longest[i] = 0;
    }
}
*/