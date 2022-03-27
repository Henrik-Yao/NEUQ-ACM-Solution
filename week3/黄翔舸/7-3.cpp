

#include<iostream>
#include<cstring>
using namespace std;
inline int jiansuo()
{
    int x = 0, f = 1;
    char c = getchar();
    while (c < '0' || c>'9')
    {
        if (c == '-')f = -1; c = getchar();
    }
    while (c >= '0' && c <= '9') { x = (x << 1) + (x << 3) + (c ^ 48); c = getchar(); }
    return x * f;
}
int n, m;
bool boom[25][25];

int er[25][25];
int stepx[4] = { -1,0,1 };
int stepy[4] = { -1,0,1 };

void dps(int x, int y)
{
    int cnt = 0;
    for (int i = 0; i <= 2; i++)
    {
        for (int j = 0; j <= 2; j++)
        {
            int nowx = x + stepx[i], nowy = y + stepy[j];
            if (nowx >= 0 && nowx < n && nowy >= 0 && nowy < m && !(nowx == x && nowy == y))
                if (boom[nowx][nowy])
                    cnt++;
        }
    }
    er[x][y] = cnt;
    if (cnt == 0)
    {
        for (int i = 0; i <= 2; i++)
        {
            for (int j = 0; j <= 2; j++)
            {
                int nowx = x + stepx[i], nowy = y + stepy[j];
                if (nowx >= 0 && nowx < n && nowy >= 0 && nowy < m && !(nowx == x && nowy == y))
                    if (er[x + stepx[i]][y + stepy[j]] == -1)
                        dps(x + stepx[i], y + stepy[j]);
            }
        }
    }
}
bool xunzhao()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            if (er[i][j] == -1 && boom[i][j] == false)
                return false;
    }
    return true;
}
int main()
{

    n = jiansuo(), m = jiansuo();
    int k = jiansuo(), l = jiansuo();
    memset(er, -1, sizeof(er));//memset将数组初始化
    for (int i = 1; i <= k; i++)
    {
        int x = jiansuo(), y = jiansuo();
        boom[x][y] = true;
    }
    for (int i = 1; i <= l; i++)
    {

        int x = jiansuo(), y = jiansuo();
        if (er[x][y] != -1)
        {
            continue;
        }
        else if (boom[x][y])
        {

            cout << "You lose" << endl; break;
        }
        dps(x, y);

        for (int i = 0; i < n; i++)
        {

            for (int j = 0; j < m; j++)
            {



                cout << er[i][j] << " ";
            }
            cout << endl;

        }

        if (xunzhao())
        {
            cout << "You win" << endl;
            return 0;
        }
        cout << endl;
    }


}