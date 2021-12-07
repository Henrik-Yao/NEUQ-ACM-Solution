#include <bits/stdc++.h>
using namespace std;
int t, n;
int main()
{
    cin >> t;
    while (t--)
    {
        cin >> n;
        int st[n], ed[n];
        for (int i = 0; i < n; i++) cin >> st[i] >> ed[i];
        for (int i = 0; i < n; i++) for (int j = 0; j < n - i - 1; j++) if (ed[j] > ed[j + 1]) swap(ed[j], ed[j + 1]), swap(st[j], st[j + 1]);
        int cnt = 1;
        for (int i = 1, j = 0; i < n; i++) if (st[i] >= ed[j]) j = i, cnt++;
        cout << n - cnt << endl;
    }
    return 0;
}


