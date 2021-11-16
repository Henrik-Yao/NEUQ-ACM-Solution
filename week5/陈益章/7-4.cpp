#include <iostream>
using namespace std;
struct a
{
    int in = 0;
    bool flag = 0;
}map[2007][2007];
void dfs(int x ,int y)
{
    if (map[x][y].flag==1)
    {
        return;
    }
    map[x][y].flag = 1;
    if(map[x+1][y].in==1)
    {
        dfs(x + 1, y);
    }
    if(map[x-1][y].in==1)
    {
        dfs(x - 1, y);
    }
    if(map[x][y+1].in==1)
    {
        dfs(x, y+1);
    }
    if(map[x][y-1].in==1)
    {
        dfs(x , y-1);
    }
}
int sum=0;
int main()
{
    int m, n;
    cin >> m >> n;
    for (int i = 1; i <= m;i++)
    {
        for (int j = 1; j <=n;j++)
            cin >> map[i][j].in;
    }
    for (int i = 1; i <= m;i++)
    {
        for (int j = 1; j <=n;j++)
        {
            if((!map[i][j].flag)&&map[i][j].in==1)
            {
                dfs(i, j);
                sum++;
            }
        }
    }
    cout << sum;
}
