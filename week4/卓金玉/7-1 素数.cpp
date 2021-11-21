#include <bits/stdc++.h>
using namespace std;
int prime(int m);
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0);
    int n, m;
    while (cin >> n >> m)
    {
        int f = 0;
        for (int i = n; i <= m; ++i)
            if (prime(i) && !f)
            {
                cout << i;
                f++;
            }
            else if (prime(i))
                cout << " " << i;
        cout << endl;
    }
    return 0;
}
int prime(int m)
{
    int flag = 1, i;
    if (m == 0 || m == 1)
        flag = 0;
    for (i = 2; i <= sqrt(m); i++)
    {
        if (!(m % i))
        {
            flag = 0;
            break;
        }
    }
    return flag;
}