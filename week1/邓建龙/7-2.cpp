#include <iostream>

using namespace std;

const int N = 1e8 + 100;
int q[N];

int main()
{
    int n;
    cin >> n;
    int max_num = 0;
    for (int i = 0; i < n; i++) {
        cin >> q[i];
        if (max_num <= q[i]) {
            max_num = q[i];
        }
    }
    int a = 0,b = 0;
    int a1[n],b1[n];
    int tmp[max_num],tmp2[max_num];
    for (int i = 0; i < n; i++) {
        if (tmp[q[i]] != 1) {
            tmp[q[i]] = 1;
            a++;
        }
        a1[i] = a;
    }
    for (int i = n - 1; i >= 0; i--) {
        if (tmp2[q[i]] != 1) {
            tmp2[q[i]] = 1;
            b++;
            b1[i] = b - 1;
        } else {
            b1[i] = b;
        }
    }
    int max = a1[0] + b1[0];
    for (int i = 0; i < n; i++) {
        if (max <= (a1[i] + b1[i])) {
            max = a1[i] + b1[i];
        }
    }
    cout << max;
    return 0;
}

