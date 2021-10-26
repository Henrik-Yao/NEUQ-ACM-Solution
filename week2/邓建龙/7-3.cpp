iiii#include <iostream>

using namespace std;

const int N = 1e5 + 10;
int q[N],tmp[N];

void merge_sort(int q[], int l, int r)
{
    if (l >= r) return;
    int mid = (l + r) >> 1;
    merge_sort(q, l, mid);
    merge_sort(q, mid + 1, r);
    int index = 0, i = l, j = mid + 1;
    while (i <= mid && j <= r)
    {
        if (q[i] <= q[j]) {
            tmp[index++] = q[i++];
        } else {
            tmp[index++] = q[j++];
        }
    }
    while (i <= mid) tmp[index++] = q[i++];
    while (j <= r) tmp[index++] = q[j++];
    for (int m = l,w = 0; m <= r; m++,w++) {
        q[m] = tmp[w];
    }
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        scanf("%d", &q[i]);
    }
    merge_sort(q, 0, n - 1);
    for (int i = 0; i < n; i++) {
        printf("%d ", q[i]);
    }
    return 0;
}

