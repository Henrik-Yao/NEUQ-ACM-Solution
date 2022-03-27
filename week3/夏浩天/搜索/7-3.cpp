#include<iostream>
#include<string.h>
using namespace std;
const int dx[8] = { 0, 0, -1, 1, -1, -1, 1, 1 };
const int dy[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };
int n, m, k, l;
int lei[21][21], visited[21][21];
void dfs(int x, int y)
{
    int lsz = 0;
    for (int i = 0; i < 8; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && nx < n && ny >= 0 && ny < m)
            if (lei[nx][ny])
                lsz++;
    }
    visited[x][y] = lsz;
    if (!lsz)
        for (int i = 0; i < 8; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m)
                if (visited[nx][ny] == -1)
                    dfs(nx, ny);
        }
}

int main()
{
    cin >> n >> m >> k >> l;
    for (int i = 0; i < k; i++)
    {
        int xl, yl;
        cin >> xl >> yl;
        lei[xl][yl] = 1;
    }
    memset(visited, -1, sizeof(visited));
    for (int i = 0; i < l; i++)
    {
        int xd, yd;
        cin >> xd >> yd;
        if (visited[xd][yd] == -1)
        {
            if (lei[xd][yd] == 1)
            {
                cout << "You lose";
                return 0;
            }
            dfs(xd, yd);
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                    cout << visited[i][j] << " ";
                cout << endl;
            }
            int pd = 1;
            for (int i = 0; i < n; i++)
                for (int j = 0; j < m; j++)
                    if (visited[i][j] == -1 && !lei[i][j])
                        pd = 0;
            if (pd)
            {
                cout << "You win";
            }
            cout << endl;
        }
    }
}