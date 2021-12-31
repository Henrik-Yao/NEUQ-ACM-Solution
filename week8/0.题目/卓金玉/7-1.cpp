#include <bits/stdc++.h>
using namespace std;
struct duration
{
    int former;
    int latter;
};
bool cmp(duration da, duration db)
{
    return ((da.former < db.former) || ((da.former == db.former) && (da.latter < db.latter))); //定义比较法则
    // return (da.latter < db.latter);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T, N;
    cin >> T;
    while (T--)
    {
        cin >> N;
        vector<duration> a(N);
        int len[N], max = 1;
        for (int i = 0; i < N; ++i)
        {
            cin >> a[i].former >> a[i].latter;
            len[i] = 1;
        }
        sort(a.begin(), a.end(), cmp);
        // for (int i = 0; i < N; ++i)
        // {
        //     cout << "(" << a[i].former << "  " << a[i].latter << ")" << endl;
        // }
        for (int i = 1; i < N; ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                if (a[i].former >= a[j].latter && len[i] < len[j] + 1)
                {
                    len[i] = len[j] + 1;
                    len[i] > max ? max = len[i] : 1;
                }
            }
        }

        cout << N - max << endl;
    }
    return 0;
}