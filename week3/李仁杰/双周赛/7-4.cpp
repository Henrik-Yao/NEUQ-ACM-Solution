#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

long long  a[65];

int h(int n, long long now) {
    if (n == 1) return 1;
    long long m = 10000000000;
    for (int i = 1; i <= n - 1; i++) {
        if (pow(2, i) - 1 > a[n - 1]) break;
        long long t = a[n - i] * 2 + pow(2, i) - 1;
        m = min(m, t);
    }
    return m;
}

int main() {
    int n;
    for (int i = 1; i < 65; i++) {
        a[i] = h(i, 0);
    }
    while (cin >> n) {
        cout << a[n] << endl;
    }
}