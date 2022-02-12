#include<bits/stdc++.h>
using namespace std;

#define lowbit(x) (x & (-x))
typedef long long ll;
const int MAXN = 1000010;

void in(){}
template<typename T, typename ...otr_T>
void in(T &t, otr_T & ...otr)
{
    cin >> t;
    in(otr...);
}

char s[MAXN];
int n;

void solve()
{
    cin >> s + 1;
    n = strlen(s + 1);
    for(int i = 1; i <= n / 2; ++i)
    {
        if(s[i] != s[n - i + 1])
        {
            cout << "no\n";
            return;
        }
    }
    cout << "yes\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}