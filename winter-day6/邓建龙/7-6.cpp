#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
int n;
int a[N];
void quick_sort(int l, int r) {
    if (l >= r) return;
    int x = a[l];
    int i = l, j = r;
    while (i != j) {
        while (a[j] > x && i < j) j--;
        while (a[i] <= x && i < j) i++;
        if (i < j) swap(a[i], a[j]);
    }
    swap(a[l], a[i]);
    for (int m = 0; m < n; m++) printf("%d ", a[m]); printf("\n");
    quick_sort(l, j - 1), quick_sort(j + 1, r);
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    quick_sort(0, n - 1);
    for (int m = 0; m < n; m++) printf("%d ", a[m]); printf("\n");
    return 0;
}