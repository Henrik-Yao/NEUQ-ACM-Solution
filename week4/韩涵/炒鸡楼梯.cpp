/*#include<iostream>
using namespace std;
int C(int down, int up) {
    up = up < down - up ? up : down - up;
    int b = 1;
    for (int i = 1; i <= up; i++) {
        b = b * (down - i + 1);
        b = b / i;
    }
    return b;
}
int main() {
    int n;
    cin >> n;
    while (n--) {
        int a;
        int ans = 0;
        cin >> a;
        if (a == 1) {
            cout << 0 << endl;
            continue;
        }
        a = a - 1;
        int uppig = a / 2 + 1;
        int markdown = a % 2 - 2;
        while (uppig > 0) {
            uppig--;
            markdown += 2;
            ans += C(uppig + markdown, uppig);
        }
        cout << ans << endl;
    }
}*/