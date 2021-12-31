#include <bits/stdc++.h>
using namespace std;
int n;
int in[15], post[15];
void pre(int root, int l, int r)
{
    if (l > r)
        return;
    int i = l;
    while (i != r && in[i] != post[root])
    {
        ++i;
    }
    cout << post[root] << " ";
    pre(root - 1 - r + i, l, i - 1);
    pre(root - 1, i + 1, r);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> post[i];
    }
    for (int i = 0; i < n; ++i)
    {
        cin >> in[i];
    }
    pre(n - 1, 0, n - 1);
    return 0;
}
