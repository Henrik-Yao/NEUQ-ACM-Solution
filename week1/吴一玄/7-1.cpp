#include<bits/stdc++.h>
using namespace std;

int n;
string s, ss[25];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    cin >> s;
    for(int i = 1; i <= n; ++i) cin >> ss[i];
    int len = s.size();
    for(int i = 1; i <= n; ++i)
    {
        int ans = 0;
        int m = ss[i].size();
        for(int j = 0; j + m - 1 < len; ++j)
        {
            int flag = 1;
            for(int k = 0; k < m; ++k)
                if(s[j + k] != ss[i][k]) flag = 0;
            ans += flag;
        }
        cout << ans << "\n";
    }
    return 0;
}