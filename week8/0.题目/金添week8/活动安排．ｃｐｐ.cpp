#include <bits/stdc++.h>
using namespace std;
int sum = 0; //为跳跃的总次数
int path[1000001];
int flag = 0;
int f[1201011];
int getmax(int m, int n)
{
    int max = path[m] + m;
    for (int i = m; i <= n; i++)
    {
        if (path[i] + i > max)
            max = path[i] + i;
    }
    return max;
}
void greedsearch(int n)
{
    int max = 0; //6 3 1 1 1 1 2 2 3 1
    int l = 1, r = 1;
    while (r <= n)
    {
        int remp = getmax(l, r);
        for (int j = r + 1; j <= remp; ++j)
            f[j] = f[r] + 1;
        l = r + 1;
        r = remp;
    }
}
int main()
{
    int num;
    cin >> num; //道路个数
    for (int i = 1; i <= num; i++)
        cin >> path[i];
    // generate_max(num);
    greedsearch(num);
    cout << f[num];
    return 0;
}