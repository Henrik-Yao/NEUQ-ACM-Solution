#include<bits/stdc++.h>
using namespace std;

#define lowbit(x) (x & (-x))
typedef long long ll;
const int MAXN = 110;

void in(){}
template<typename T, typename ...otr_T>
void in(T &t, otr_T & ...otr)
{
    cin >> t;
    in(otr...);
}

inline int cmp(const pair<int, string> a, const pair<int, string> b)
{
    if(a.first == b.first) return a.second < b.second;
    return a.first > b.first;
}

int n;
pair<int, string> a[MAXN];

int main()
{
    in(n);
    for(int i = 1; i <= n; ++i)
        in(a[i].second, a[i].first);
    sort(a + 1, a + 1 + n, cmp);
    for(int i = 1; i <= n; ++i)
        cout << a[i].second << " " << a[i].first << "\n";
    return 0;
}