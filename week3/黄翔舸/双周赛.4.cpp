#include <iostream>

#include <cstring>

using namespace std;

int main() {
    long long int f[68];
    long long int g[68];
    f[0] = 0;
    for (int i = 1; i <= 63; i++) {
        f[i] = 2 * (f[i - 1] + 1) - 1;
    }
    long long inf = 9999999;
    fill(g + 1, g + 66, inf);
    g[1] = 1;
    g[2] = 3;
    for (int i = 3; i <= 64; i++) {
        for (int k = 1; k < i; k++) {
            if (i == 64 && k == 1)
                continue;
            g[i] = min(g[i], 2 * g[k] + f[i - k]);
        }
    }
    int n;
    while (cin >> n)
    {

        cout << g[n] << endl;
    }
    return 0;
}