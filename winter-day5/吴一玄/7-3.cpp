#include<bits/stdc++.h>
using namespace std;

#define lowbit(x) (x & (-x))
typedef long long ll;
const int MAXN = 500010;
const ll inf = 0x3f3f3f3f3f3f3f3f;

void in(){}
template<typename T, typename ...otr_T>
void in(T &t, otr_T & ...otr)
{
    cin >> t;
    in(otr...);
}

int n, a[MAXN];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    in(n);
    for(int i = 1; i <= 2 * n; ++i) in(a[i]);
    nth_element(a + 1, a + n, a + 1 + 2 * n);
    cout << a[n] << "\n";
    return 0;
}