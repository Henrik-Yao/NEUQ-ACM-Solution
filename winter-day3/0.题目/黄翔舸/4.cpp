#include <iostream>
using namespace std;
int a[2016][2016], b[2016][2016], sum = 0;
int dx[4] = { 0,0,1,-1 }, dy[4] = { 1,-1,0,0 };
int n, m;
void ss(int x, int y)
{
    int i;
    for (i = 0; i < 4; i++)
    {
        int tr = x + dx[i], tu = y + dy[i];
        if (tr >= 0 && tu >= 0 && tr <= n && tu <= m && a[tr][tu] == 1 && b[tr][tu] == 0)
        {
            b[tr][tu] = 1;
          ss(tr, tu);
        }
    }
}
int main()
{
    int i, j;
    cin >> m >> n;
    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++)
            cin >> a[i][j];
    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++)
            if (a[i][j] == 1 && b[i][j] == 0)
            {
                ss(i, j);
                sum++;
            }
    cout << sum;
}