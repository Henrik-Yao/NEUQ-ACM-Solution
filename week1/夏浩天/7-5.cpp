#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    int cx[10000];
    string xm[10000];
    int qw, gs;
    int end = 1;
    for (int i = 1;i <= n;i++)//写入朝向与姓名
    {
        cin >> cx[i] >> xm[i];
    }
    for (int i = 0;i < m;i++)//写入操作
    {
        cin >> qw >> gs;//写入方向与个数, 0方向且0朝向 向上
        if ((qw == 0 && cx[end] == 0) || (qw == 1 && cx[end] == 1))
        {
            end -= gs;
        }
        else if ((qw == 1 && cx[end] == 0) || (qw == 0 && cx[end] == 1))
        {
            end += gs;
        }
        while (end <= 0)
        {
            end = n + end;
        }
        if (end > n)
        {
            end = end % n;
        }
    }
    cout << xm[end];
    return 0;
}