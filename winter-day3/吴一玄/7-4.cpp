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

const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, -1, 0, 1};

int n, m, a[MAXN][MAXN];

void dfs(int x, int y)
{
    a[x][y] = 0;
    for(int i = 0; i < 4; ++i)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 1 || nx > n || ny < 1 || ny > m) continue;
        if(!a[nx][ny]) continue;
        dfs(nx, ny);
    }
}

int main()
{
    in(n, m);
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j) in(a[i][j]);
    int ans = 0;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            if(a[i][j])
            {
                dfs(i, j);
                ++ans;
            }
    cout << ans << "\n";
    return 0;
}