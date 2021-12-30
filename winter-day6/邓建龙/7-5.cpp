#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
int n;
int a[N];
void adjustHeap(int i, int len) {
    int tmp = a[i];
    for (int k = i * 2 + 1; k < len; k = k * 2 + 1) {
        if (k + 1 < len && a[k] < a[k + 1]) k++;
        if (a[k] > tmp) a[i] = a[k], i = k;
        else break;
    }
    a[i] = tmp;
}
void HeapSort() {
    // 1. 构建大顶堆
    for (int i = n / 2 - 1; i >= 0; i--) {
        adjustHeap(i, n);
    }
    // 
    for (int i = 0; i < n; i++) printf("%d ", a[i]); puts("");
    // 2. 调整堆结构
    for (int i = n - 1; i >= 0; i--) {
        swap(a[i], a[0]);
        adjustHeap(0, i);
        if (i != 0) {for (int j = 0; j < n; j++) printf("%d ", a[j]); printf("\n");}
    }
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    HeapSort();
    return 0;
}