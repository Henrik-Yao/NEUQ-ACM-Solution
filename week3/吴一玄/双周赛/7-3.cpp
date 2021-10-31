#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll f[40];

int main()
{
    f[1] = 2;
    for(int i = 2; i <= 35; ++i) f[i] = 3ll * f[i - 1] + 2ll;
    int n;
    while(cin >> n) cout << f[n] << "\n";
}