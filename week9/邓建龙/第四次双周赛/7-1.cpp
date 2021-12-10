#include <bits/stdc++.h>
using namespace std;
const int N = 1000;
int n, m, q[N], s[N];
void func(int l, int r)
{
    while (l <= r) {
        swap(s[l], s[r]);
        l++, r--;
    }
}
int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) scanf("%d", &q[i]);
    sort(q, q + n);
    int len = q[n - 1] - q[0] + 1;
    for (int i = 0; i < n - 1; i++) s[i] = q[i + 1] - q[i] - 1;
    sort(s, s + n - 1);
    func(0, n - 2);
    int sum = len;
    for (int i = 0; i < m - 1; i++) sum = sum - s[i];
    cout << sum;
    return 0;
}

