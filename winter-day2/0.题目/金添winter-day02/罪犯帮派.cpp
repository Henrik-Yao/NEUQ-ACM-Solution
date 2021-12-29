#include <bits/stdc++.h>
using namespace std;
//并查集
int member[1001];
int search(int n)
{
    if (member[n] == n)
        return n; //该人为代表人
    else
        return search(member[n]); //查询该帮派后的代表人
}
int main()
{
    int n, m, q;
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++)
        member[i] = i; //赋初值

    for (int i = 0; i < m; i++)
    {
        int remp1, remp2;
        cin >> remp1 >> remp2;
        if (remp1 > remp2)
            swap(remp1, remp2); //确保remp2>remp1
        member[search(remp1)] = member[remp2]; //将两个帮派合并（即让一个帮派的老大听从另一个帮派的老大）
    }
    for (int i = 0; i < q; i++)
    {
        int remp1, remp2;
        cin >> remp1 >> remp2;
        if (search(remp1) == search(remp2))
        {
            cout << "In the same gang." << endl;
        }
        else
        {
            cout << "In different gangs." << endl;
        }
    }
    int sum = 0; //帮派总数
    for (int i = 1; i <= n; i++)
    {
        if (member[i] == i)
            sum++;
    }
    cout << sum << endl;
    return 0;
}