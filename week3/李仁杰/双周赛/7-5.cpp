#include <iostream>
using namespace std;

void merge(int* a, int* b, int n, int m) {
    int i = 0, j = 0;
    int* ans = new int[n + m + 2];
    for (int k = 0; k <= n + m + 1; k++) {
        if (i > n) ans[k] = b[j++];
        else if (j > m) ans[k] = a[i++];
        else if (a[i] < b[j]) ans[k] = a[i++];
        else ans[k] = b[j++];
    }
    for (int k = 0; k <= m + n; k++) cout << ans[k] << ' ';
    cout << ans[n + m + 1] << endl;
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n, m;
        cin >> n;
        int* a = new int[n];
        for (int j = 0; j < n; j++) cin >> a[j];
        cin >> m;
        int* b = new int[m];
        for (int j = 0; j < m; j++) cin >> b[j];
        merge(a, b, n - 1, m - 1);
    }
}