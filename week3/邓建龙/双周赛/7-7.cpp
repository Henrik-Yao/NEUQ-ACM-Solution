#include <iostream>

using namespace std;

const int N = 1e6 + 10;
int n;
int q[N], tmp[N];

long long func(int l, int r, long long tot)
{
    if (l >= r) return 0;
    int mid = (l + r) / 2;
    long long L = func(l, mid, 0), R = func(mid + 1, r, 0);
    int i = l, j = mid + 1, index = 0;
    while (i <= mid && j <= r) {
        if (q[i] <= q[j]) {
            tmp[index++] = q[i++];
        } else {
            tmp[index++] = q[j++];
            tot += mid - i + 1;
        }
    }
    while (i <= mid) tmp[index++] = q[i++];
    while (j <= r) tmp[index++] = q[j++];
    for (int k = l,g = 0; k <= r; k++,g++) {
        q[k] = tmp[g];
    }
    return L + R + tot;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> q[i];
    }
    long long res = func(0, n - 1, 0);
    cout << res;
    return 0;
}