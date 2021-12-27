#include <bits/stdc++.h>
using namespace std;
int n;
int pre[15], in[15];
void post(int root, int l, int r)
{
    if (l > r)
    {
        return;
    }
    int i = l;
    while (i != r && in[i] != pre[root])
    {
        ++i;
    }
    post(root + 1, l, i - 1);
    post(root + 1 + i - l, i + 1, r);
    cout << pre[root] << " ";
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> pre[i];
    }
    for (int i = 0; i < n; ++i)
    {
        cin >> in[i];
    }
    post(0, 0, n - 1);
    return 0;
}
