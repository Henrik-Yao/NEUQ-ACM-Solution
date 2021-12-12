#include <bits/stdc++.h>
using namespace std;
const int N = 55;
long long n, q[N];
int main()
{
    q[1] = 1, q[2] = 2, q[3] = 4;
    for (int i = 4; i < N; i++) q[i] = q[i - 1] + q[i - 2] + q[i - 3];
    while (cin >> n) printf("%lld\n", q[n]);
    return 0;
}

