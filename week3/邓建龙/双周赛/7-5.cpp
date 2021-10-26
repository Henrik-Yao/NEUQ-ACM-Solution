#include <iostream>

using namespace std;

int main()
{
    int num, m, n;
    cin >> num;
    for (int i = 0; i < num; i++) {
        scanf("%d", &m);
        int a[m];
        for (int j = 0; j < m; j++) {
            scanf("%d", &a[j]);
        }
        scanf("%d", &n);
        int b[n];
        for (int j = 0; j < n; j++) {
            scanf("%d", &b[j]);
        }
        int c[n + m + 30];
        int u = 0, v = 0, index = 0;
        while (u < m && v < n) {
            if (a[u] <= b[v]) {
                c[index++] = a[u++];
            } else {
                c[index++] = b[v++];
            }
        }
        while (u < m) c[index++] = a[u++];
        while (v < n) c[index++] = b[v++];
        for (int j = 0; j < m + n; j++) {
            j != m + n - 1 ? cout << c[j] << " " : cout << c[j];
        }
        cout << endl;
    }
    return 0;
}