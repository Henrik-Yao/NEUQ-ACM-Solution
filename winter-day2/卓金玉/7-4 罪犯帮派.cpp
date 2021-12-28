#include <bits/stdc++.h>
using namespace std;
#define N 1005
int gang[N];
int cnt;
int init()
{
    for (int i = 0; i < N; ++i)
    {
        gang[i] = i;
    }
}
int stand(int a)
{
    return gang[a] == a ? a : stand(gang[a]);
}
int merge(int a, int b)
{
    gang[stand(a)] = stand(b);
}
bool quest(int a, int b)
{
    return stand(a) == stand(b);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m, q;
    cin >> n >> m >> q;
    init();
    int a, b, qa, qb;
    cnt = n;
    for (int i = 0; i < m; ++i)
    {
        cin >> a >> b;
        merge(a, b);
        cnt--;
    }
    for (int i = 0; i < q; ++i)
    {
        cin >> qa >> qb;
        if (quest(qa, qb))
        {
            cout << "In the same gang." << endl;
        }
        else
        {
            cout << "In different gangs." << endl;
        }
    }
    // for (int i = 1; i <= n; ++i)
    // {
    //     // cout << "- - -" << endl
    //     //      << "gang[" << i << "] = " << gang[i] << endl;
    //     // for (int j = 1; j < i; ++j)
    //     // {

    //     // }
    //     if (!quest(i, 1))
    //     {
    //         cnt++;
    //     }
    // }
    cout << cnt << endl;
    return 0;
}
