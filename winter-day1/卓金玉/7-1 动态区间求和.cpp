#include <bits/stdc++.h>
using namespace std;
#define N 1000005
#define lowbit(i) ((i) & (-i))
long long a[N];
int n;
void add(int k, int num)
{
    for (int i = k; i <= n; i = i + lowbit(i))
    {
        a[i] = a[i] + num;
    }
}
long long Sum(int k)
{
    long long sum = 0;
    for (int i = k; i > 0; i = i - lowbit(i))
    {
        sum = sum + a[i];
    }
    return sum;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int q;
    cin >> n >> q;
    memset(a, 0, sizeof(a));
    for (int i = 1; i <= n; ++i)
    {
        int t;
        cin >> t;
        add(i, t);
    }
    int questnum, temp, x, l, r;
    for (int i = 0; i < q; ++i)
    {
        cin >> questnum;
        if (questnum == 1)
        {
            cin >> temp >> x;
            add(temp, x);
        }
        else
        {
            cin >> l >> r;
            cout << Sum(r) - Sum(l - 1) << endl;
        }
    }
    return 0;
}
