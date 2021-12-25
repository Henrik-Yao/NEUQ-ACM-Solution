#include<iostream>
#include<algorithm>
using namespace std;
int a[100000];
int jl[99999];//统计相邻数差值
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    for (int i = 0; i < n - 1; i++)
        jl[i] = a[i + 1] - a[i] - 1;
    sort(jl, jl + n - 1);
    int len = a[n - 1] - a[0] + 1;
    int gs = n - 2;
    for (int j = 0; j < m - 1; j++)
    {
        len = len - jl[gs];
        gs--;
    }
    cout << len;
}