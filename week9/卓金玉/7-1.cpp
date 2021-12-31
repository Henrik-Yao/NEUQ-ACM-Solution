#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    while (cin >> n)
    {
        long long a[51];
        a[1] = 1;
        a[2] = 2;
        a[3] = 4;
        if (n >= 4)
        {
            for (int i = 4; i <= n; ++i)
            {
                a[i] = a[i - 1] + a[i - 2] + a[i - 3];
            }
        }
        cout << a[n] << endl;
    }
}