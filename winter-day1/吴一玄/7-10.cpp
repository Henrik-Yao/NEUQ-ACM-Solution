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

int n, m;
vector<int> ans[110];

int main()
{
    in(n);
    for(int i = 1; i <= n; ++i)
    {
        int x; in(x);
        int mn = 0x7fffffff, id = 0;
        for(int j = 1; j <= m; ++j)
        {
            int v = ans[j][ans[j].size() - 1];
            if(v > x && v < mn)
            {
                mn = v;
                id = j;
            }
        }
        if(!id)
        {
            ++m;
            ans[m].push_back(x);
        }
        else
        {
            ans[id].push_back(x);
        }
    }
    int id = 0;
    for(int i = 1; i <= m; ++i)
        for(auto j: ans[i]) if(j == 1) id = i;
    cout << ans[id][0];
    for(int i = 1; i < ans[id].size(); ++i)
        cout << " " << ans[id][i];
    cout << "\n";
    cout << m << "\n";
    return 0;
}