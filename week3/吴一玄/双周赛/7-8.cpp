#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int a[1000010];

int main()
{
    int n, x;
    cin >> n >> x;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    sort(a + 1, a + 1 + n);
    cout << lower_bound(a + 1, a + 1 + n, x) - a << "\n";
}