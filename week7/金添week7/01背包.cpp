#include <bits/stdc++.h>
using namespace std;
int dp[10000][10000]; //前者为背包物品数目，后者为总容量，数组存的是此时的最大价值
int value[10000];
int room[10000];
int main()
{
    int num, space;
    while (cin >> num >> space)
    {
        for (int i = 1; i <= num; i++)
            cin >> room[i];
        for (int i = 1; i <= num; i++)
            cin >> value[i];
        for (int i = 1; i <= num; i++) //i的值为物品编号
        {
            for (int j = 1; j <= space; j++) //j的值是背包的容量
            {
                if (room[i] > j) //背包放不下
                    dp[i][j] = dp[i - 1][j];
                else //背包放得下
                    dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - room[i]] + value[i]);
            }
        }
        int max1 = 0;
        for (int i = 1; i <= num; i++)
        {
            for (int j = 1; j <= space; j++)
            {
                max1 = max(dp[i][j], max1);
            }
        }
        cout << max1<<endl;
        for (int i = 1; i <= num; i++)
        {
            value[i] = 0;
            room[i] = 0;
            for (int j = 1; j <= space; j++)
            {
                dp[i][j] = 0;
            }
        }
    }
    return 0;
}