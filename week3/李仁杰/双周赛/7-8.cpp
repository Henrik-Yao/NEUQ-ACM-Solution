#include <iostream>
using namespace std;

int* a, ob, n;

void find(int lo, int hi) {
    if (lo + 1 >= hi) {
        if (hi == 0) {
            if (a[hi] >= ob) cout << 1;
            else cout << n + 1;
            return;
        }
        if (a[lo] >= ob) cout << hi;
        else if (a[hi] >= ob) cout << hi + 1;
        else cout << n + 1;
        return;
    }
    int mid = (lo + hi) / 2;
    if (a[mid] >= ob) find(lo, mid);
    else find(mid, hi);
}

int main() {
    while (cin >> n >> ob) {
        a = new int[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        find(0, n - 1);
    }
}