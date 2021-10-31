/*#include<iostream>
#include<math.h>
typedef unsigned long long ull;
using namespace std;
ull dp[10001];
void cal(int a) {
    ull min = 1;
    for (int i = 1; i < a; i++) {
        ull ans = 2 * dp[i] + pow(2, a - i) - 1;
        if (min == 1)min = ans;
        else min = min < ans ? min : ans;
    }
    dp[a] = min;
}
int main() {
    dp[0] = 0;
    dp[1] = 1;
    int temp = 1;
    int t;
    while (scanf_s("%d", &t) != EOF) {
        if (temp < t) for (int i = temp; i <= t; i++) cal(i);
        cout << dp[t] << endl;
    }
    return 0;
}*/