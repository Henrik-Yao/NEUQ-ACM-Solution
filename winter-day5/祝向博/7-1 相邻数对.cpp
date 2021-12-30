#include <bits/stdc++.h>
using namespace std;
int N, a[1005], Ans;
int main() {
    cin >> N;
    for (int i = 1; i <= N; ++i) cin >> a[i];
    for (int i = 1; i <= N; ++i)
        for (int j = i + 1; j <= N; ++j)
            if (abs(a[i] - a[j]) == 1) ++Ans;
    cout << Ans;
    return 0;
}
