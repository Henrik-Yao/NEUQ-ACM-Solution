#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    double q[65], w[65];
    q[1] = 1;
    for (int i = 2; i <= 64; i++) q[i] = 2 * q[i - 1] + 1, w[i] = 1.84467e+0300;
    w[1] = 1;
    for (int i = 2; i <= 64; i++) {
        for (int j = 1; j < i; j++) {
            w[i] = min(w[i], w[j] * 2 + q[i - j]);
        }
    }
    while (cin >> n)
    {
        cout << w[n] << endl;
    }
    return 0;
}