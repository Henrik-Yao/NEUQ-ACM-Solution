#include<iostream>
using namespace std;

int b[1505];
int w[405];
int p[405];

int main() {
    int n, m;
    while (cin >> n >> m) {
        for (int i = 1; i <= n; i++) cin >> w[i];
        for (int i = 1; i <= n; i++) cin >> p[i];
        for (int i = 0; i < n; i++) b[i] = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = m; j >= w[i]; j--) {
                b[j] = b[j] > b[j - w[i]] + p[i] ? b[j] : b[j - w[i]] + p[i];
            }
        }
        int ans = b[m];
        cout << ans << endl;
        for (int i = 0; i <= m; i++) b[i] = 0;
    }
}