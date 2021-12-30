#include <bits/stdc++.h>
using namespace std;
inline int read() {
    int ret = 0, f = 1; char ch = getchar();
    for (; !isdigit(ch); ch = getchar()) if (ch == '-') f = -f;
    for (; isdigit(ch); ch = getchar()) ret = ret * 10 + ch - 48;
    return ret * f;
}
int N, Sum, a[2000005];
int main() {
    N = read();
    for (int i = 1; i <= N; ++i) a[i] = read();
    int x = read();
    int L = 1, R = N;
    while (L <= R) {
        int mid = L + (R - L >> 1);
        if (++Sum, a[mid] == x)
            return printf("%d\n%d\n", mid - 1, Sum), 0;
        if (a[mid] > x) R = mid - 1;
        else L = mid + 1;
    }
    printf("-1\n%d\n", Sum);
    return 0;
}
