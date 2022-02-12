#include <bits/stdc++.h>
using namespace std;
const int N = 1000;
int s[N], q[N], n, m, k;
int main()
{
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) q[i] = 1, s[i] = 1;
    int num = n, op = 1;
    int i = 1;
    while (num) {
        if (op == 1) {
            int x = 1;
            while (x < m) {
                i--; if (i < 1) i = i + n;
                if (s[i] == 1) x++;
            }
            cout << i << " ";
            s[i] = 0; i--; num--; op = -1 * op;
        } else {
            int x = 1;
            while (x < k) {
                i++; if (i > n) i = i - n;
                if (s[i] == 1) x++;
            }
            cout << i << " "; s[i] = 0; i++; num--; op = -1 * op;
        }
    }
    return 0;
}