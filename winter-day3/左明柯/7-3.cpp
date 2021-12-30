#include<bits/stdc++.h>
using namespace std;

#define lowbit(x) (x & (-x))
typedef long long ll;
const int MAXN = 100010;

void in(){}
template<typename T, typename ...otr_T>
void in(T &t, otr_T & ...otr)
{
    cin >> t;
    in(otr...);
}

int n, a[MAXN];
map< vector<int>, int> H;

int main()
{
    in(n); int ans = 0;
    for(int i = 1; i <= n; ++i) in(a[i]);
    for(int i = 0; i < (1 << n); ++i)
    {
        vector<int> sum;
        for(int j = 0; j < n; ++j)
            if((i >> j) & 1) sum.push_back(a[j + 1]);
        if(sum.size() <= 1) continue;
        int flag = 1;
        for(int j = 1; j < sum.size(); ++j)
            if(sum[j] < sum[j - 1]) flag = 0;
        if(!flag) continue;
        if(H.count(sum)) continue;
        H[sum] = 1;
        ++ans;
    }
    cout << ans << "\n";
    return 0;
}
