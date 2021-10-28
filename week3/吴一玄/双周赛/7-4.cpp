#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

ull getg(int n)
{
    return (1ull << n) - 1ull;
}

ull f[65];

ull getf(int n)
{
    if(f[n]) return f[n];
    f[n]--;
    for(int a = 1; a <= n - 1; ++a)
    {
        int b = n - 1 - a;
        f[n] = min(f[n], getf(a) + getg(b) + 1ull + getg(b) + getf(a));
    }
    return f[n];
}

int main()
{
    f[1] = 1;
    int n;
    while(cin >> n) cout << getf(n) << "\n";
}