#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
int n;
int a[N];
int x;
int tot = 0;
int BinarySearch(int l, int r) {
    while (l < r) {
        tot++;
        int mid = l + r >> 1;
        if (a[mid] == x) return mid;
        if (a[mid] > x) r = mid - 1; // 如果上面的成立，这里大于等于只是大于
        if (a[mid] < x) l = mid + 1;
    }
    tot++; // 一定要加这一次  不然比较次数错误
    if (a[l] == x) return l;
    else return -1;
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    cin >> x;
    int i = 0, j = n - 1;
    int ans = BinarySearch(i, j);
    cout << ans << endl << tot << endl;
    return 0;
}