#include <iostream>
using namespace std;

const int N = 1005;
int q[N], f[N];

int main()
{
    int t;
    cin >> t;
    int t1 = t;
    while (t1--)
    {
        if (t1 != t - 1) cout << endl;
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> q[i], f[i] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j < i; j++) {
                if (q[j] < q[i]) f[i] = max(f[i], f[j] + 1);
            }
        }
        int ans = -1;
        for (int i = 1; i <= n; i++) ans = max(ans, f[i]);
        cout << ans << endl;
    }
    return 0;
}