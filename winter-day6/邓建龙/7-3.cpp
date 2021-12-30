#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n, q[N], x;
int main()
{
    memset(q, 0, sizeof q);
    cin >> n;
    while (n--) {
        scanf("%d", &x);
        q[x]++;
    }
    for (int i = 0; i < N; i++) {
        if (q[i] != 0) cout << i << ":" << q[i] << endl;
    }
    return 0;
}