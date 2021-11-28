#include<bits/stdc++.h>
using namespace std;

const int N = 1010;
int n, m;
int a[N];
int v[N], w[N];
int main()
{
    while (cin >> n >> m)
    {
        memset(v, 0, sizeof v), memset(w, 0, sizeof w), memset(a, 0, sizeof a);
        for (int i = 1; i <= n; i++)
        {
            cin >> v[i];
        }
        for (int i = 1; i <= n; i++)
        {
            cin >> w[i];
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = m; j >= v[i]; j--)
            {
                a[j] = max(a[j], a[j - v[i]] + w[i]);
            }
        }
        cout<<a[m]<<endl;
    }

    return 0;
}
