#include <iostream>
using namespace std;
const int N = 1000000;
int q[N];
typedef long long LL;
LL res;

LL merge_sort(int q[], int l, int r)
{
    if (l >= r)return 0;
    LL t = 0;
    int mid = l + r >> 1;
    t = merge_sort(q, l, mid) + merge_sort(q, mid + 1, r);
    int k = 0, i = l, j = mid + 1;
    int tmp[r - l + 1];
    while (i <= mid && j <= r)
    {
        if (q[i] <= q[j])tmp[k++] = q[i++];
        else
        {
            t += mid - i + 1;
            tmp[k++] = q[j++];
        }
    }
    while (i <= mid)tmp[k++] = q[i++];
    while (j <= r)tmp[k++] = q[j++];
    for (int i = l, j = 0; i <= r; i++, j++)q[i] = tmp[j];
    return t;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)cin >> q[i];
    res = merge_sort(q, 0, n - 1);
    cout << res;
    return 0;

}
