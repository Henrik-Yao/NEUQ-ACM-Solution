#include <bits/stdc++.h>
using namespace std;
int ma[50][50], rea[50][50];
bool vis[50][50];
int n, m, k, l;
int dd[8][2] = {-1, 0, 1, 0, 0, -1, 0, 1, -1, -1, -1, 1, 1, -1, 1, 1};
bool check(int x, int y)
{
    if (x < 0 || x >= n || y < 0 || y >= m)
        return false;
    return true;
}
void dfs(int x, int y)
{
    vis[x][y] = 1;
    if (ma[x][y] != 0)
    {
        rea[x][y] = ma[x][y];
        return;
    }
    if (ma[x][y] == 0)
        rea[x][y] = 0;
    for (int i = 0; i < 8; i++)
    {
        int dx = x + dd[i][0], dy = y + dd[i][1];
        if (check(dx, dy) && !vis[dx][dy])
        {
            dfs(dx, dy);
        }
    }
}
bool winn()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (ma[i][j] != 1e9 && rea[i][j] == -1)
            {
                return  false;
            }
        }
    }
    return true;
}
int main()
{
    cin >> n >> m >> k >> l;
    for (int i = 0; i < k; i++)
    {
        int xx, yy;
        cin >> xx >> yy;
        ma[xx][yy] = 1e9;
        for (int j = 0; j < 8; j++)
        {
            int dx = xx + dd[j][0], dy = yy + dd[j][1];
            if (check(dx, dy)&&ma[dx][dy]!=1e9)
                ma[dx][dy]++;
        }
    }
    memset(rea, -1, sizeof rea);
    bool flag = 1;
    bool fir = 0,OK=0;
    for (int i = 0; i < l; i++)
    {
        int xx, yy;
        cin >> xx >> yy;
        if (vis[xx][yy]) continue;
        if (ma[xx][yy] == 1e9)
        {
            cout << "You lose" ;
            return 0;
        }
        else 
        {
        dfs(xx, yy);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                printf("%d ", rea[i][j]);
            }
            cout << endl;
        }
        if(winn()) 
        {
            cout<<"You win";
            return 0;
        }
        else cout<<endl;
        }
    }
    return 0;
}
