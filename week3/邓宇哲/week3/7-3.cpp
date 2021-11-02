#include <iostream>
using namespace std;
struct point
{
    bool lei = 0;
    int value = -1;
};
point a[22][22];
int n, m, k, l, area = 0;
void dfs(int, int);
bool ifout(int, int);
int  main()
{
    cin >> n >> m >> k >> l;
    for (int t = 0; t < k; t++)
    {
        int i, j;

        cin >> i >> j;
        a[i][j].lei = 1;
    }
    for (int t = 0; t < l; t++)
    {
        int i, j;
        cin >> i >> j;
        if (a[i][j].value != -1)
            continue;
        else if (a[i][j].lei)
        {
            cout << "You lose";
            return 0;
        }
        else
        {
            dfs(i, j);
            for (int o = 0; o < n; o++)
            {
                for (int p = 0; p < m; p++)
                {
                    cout << a[o][p].value << ' ';
                }
                cout << endl;
            }
        }
        if (area == m * n - k)
        {
            cout << "You win";
            return 0;
        }
        cout << endl;
    }
    return 0;
}
bool ifout(int i, int j)
{
    return !(i < 0 || j < 0 || i >= n || j >= m);
}
void dfs(int i, int j)
{
    if (a[i][j].value != -1 || !(ifout(i, j)))
    {
        return;
    }
    a[i][j].value = 0;
    area++;
    if (ifout(i + 1, j + 1))
    {
        if (a[i + 1][j + 1].lei)
        {
            a[i][j].value++;
        }
        
    }
    if (ifout(i + 1, j))
    {
        if (a[i + 1][j].lei)
        {
            a[i][j].value++;
        }
        
    }
    if (ifout(i + 1, j - 1))
    {
        if (a[i + 1][j - 1].lei)
        {
            a[i][j].value++;
        }
        
    }
    if (ifout(i, j + 1))
    {
        if (a[i][j + 1].lei)
        {
            a[i][j].value++;
        }
       
    }
    if (ifout(i, j - 1))
    {
        if (a[i][j - 1].lei)
        {
            a[i][j].value++;
        }
        
    }
    if (ifout(i - 1, j))
    {
        if (a[i - 1][j].lei)
        {
            a[i][j].value++;
        }
        
    }
    if (ifout(i - 1, j - 1))
    {
        if (a[i - 1][j - 1].lei)
        {
            a[i][j].value++;
        }
        
    }
    if (ifout(i - 1, j + 1))
    {
        if (a[i - 1][j + 1].lei)
        {
            a[i][j].value++;
        }
        
    }
    if (a[i][j].value > 0)
        return;
    if (ifout(i + 1, j + 1)&&a[i+1][j+1].value==-1)
    {
        dfs(i + 1, j + 1);
    }
    if (ifout(i + 1, j)&&a[i+1][j].value==-1)
    {

        dfs(i + 1, j);
    }
    if (ifout(i + 1, j - 1)&&a[i+1][j-1].value==-1)
    {

        dfs(i + 1, j - 1);
    }
    if (ifout(i, j + 1)&&a[i][j+1].value==-1)
    {

        dfs(i, j + 1);
    }
    if (ifout(i, j - 1)&&a[i][j-1].value==-1)
    {

        dfs(i, j - 1);
    }
    if (ifout(i - 1, j)&&a[i-1][j].value==-1)
    {

        dfs(i - 1, j);
    }
    if (ifout(i - 1, j - 1)&&a[i-1][j-1].value==-1)
    {

        dfs(i - 1, j - 1);
    }
    if (ifout(i - 1, j + 1)&&a[i-1][j+1].value==-1)
    {

        dfs(i - 1, j + 1);
    }
}