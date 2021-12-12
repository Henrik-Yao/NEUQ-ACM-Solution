#include <bits/stdc++.h>
using namespace std;
#define N 1000005
int a[N];
int find(int l, int r, int a[])
{
    int re = l + 1;
    for (int i = l; i <= r; i++)
    {
        if (a[i] > a[l])
        {
            a[l] = a[i];
            re = i;
        }
    }
    return re;
}
int renew(int l, int r, int a[])
{
    int re = l;
    for (int i = re; i <= r; i++)
    {
        if (a[l] < a[i] + (i - l))
        {
            l = i;
        }
    }
    return l;
}
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int j = 0, temp = 1, step, findj;
    while (j + a[j] < n - 1)
    {
        int step = a[j];
        int findj = find(j, a[j] + j, a);
        j = renew(findj, step + j, a);
        temp++;
    }
    cout << temp << endl;
    return 0;
}