#include <algorithm>
#include <iostream>
using namespace std;
struct node
{
    int num = 0;
    bool done = 0;
};
node nodes[2002][2002];
void dfs(int, int);
int sum=0;
main()
{
    int m, n;
    cin >> m >> n;
    for (int i = 1; i <= m;i++)
    {
        for (int j = 1; j <=n;j++)
        {
            cin >> nodes[i][j].num;
        }
    }
    for (int i = 1; i <= m;i++)
    {
        for (int j = 1; j <=n;j++)
        {
            if((!nodes[i][j].done)&&nodes[i][j].num==1)
            {
                dfs(i, j);
                sum++;
            }
        }
    }
    cout << sum;
}
void dfs(int i ,int j)
{
    if (nodes[i][j].done==1)
    {
        return;
    }
    nodes[i][j].done = 1;
    if(nodes[i+1][j].num==1)
    {
        dfs(i + 1, j);
    }
    if(nodes[i-1][j].num==1)
    {
        dfs(i - 1, j);
    }
    if(nodes[i][j+1].num==1)
    {
        dfs(i, j+1);
    }
    if(nodes[i][j-1].num==1)
    {
        dfs(i , j-1);
    }
}