#include<iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int x;
    cin >> x;
    int cnt = 1;
    int p;
    for (int i = 0, j = n - 1;; cnt++) {
        p = (i + j) / 2;

        if (a[p] == x) {

            cout << p << endl << cnt; break;
        }
        else if (a[p] < x) {

            i = p + 1;
        }
        else {

            j = p - 1;
        }
        if (i > j) {
            cout << -1 << endl << cnt;
            break;
        }

    }
}
