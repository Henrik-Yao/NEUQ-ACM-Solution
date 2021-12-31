#include<bits/stdc++.h>
using namespace std;
int a[105],b[105];
int ans(int n, int m)
{
    int s = 0;
    for (int i = 0; i < n - m; i++) s += b[i];//取前n-m个最短间隔连接
    s += n;
    return s;
}
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n);//排序
    for (int i = 0; i < n - 1; i++) b[i] = a[i + 1] - a[i]-1;//求各区间的间隔
    sort(b, b + n - 1);//排序使最短的几段在前面从而连接能有长度和最短
    cout << ans(n, m);
    return 0;
}