#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e5 + 10;
int q[N];

long long func(int l, int r)
{
    if (l >= r) return q[l];
    int mid = (l + r) / 2;
    long long L = func(l, mid),R = func(mid + 1, r);
    long long ll = -2147483647, rr = -2147483647;
    long long s = 0;
    for (int i = mid; i >= 0; i--) {
        s += q[i];
        ll = max(ll, s);
    }
    long long s1 = 0;
    for (int i = mid + 1; i <= r; i++) {
        s1 += q[i];
        rr = max(rr, s1);
    }
    return max(max(L, R), ll + rr);
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i ++) {
        cin >> q[i];
    }
    long long res = func(0, n - 1);
    if (res < 0) {
        cout << 0 << endl;
    } else {
        cout << res << endl;
    }
    return 0;
}