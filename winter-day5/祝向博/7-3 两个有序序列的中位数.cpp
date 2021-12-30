#include <bits/stdc++.h>
using namespace std;
inline int read() {
    int ret = 0, f = 1; char ch = getchar();
    for (; !isdigit(ch); ch = getchar()) if (ch == '-') f = -f;
    for (; isdigit(ch); ch = getchar()) ret = ret * 10 + ch - 48;
    return ret * f;
}
int N, a[2000005];
int main() {
    N = read();
    for (int i = 1; i <= N * 2; ++i) a[i] = read();
    sort(a + 1, a + 1 + N * 2);
    printf("%d", a[N]);
    return 0;
}
