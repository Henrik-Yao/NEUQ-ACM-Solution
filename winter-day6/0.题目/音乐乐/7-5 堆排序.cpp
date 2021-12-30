#include <bits/stdc++.h>
using namespace std;


void display(int a[], int size) 
{
    for (int i = 0; i < size; i++) 
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void swap(int a[], int x, int y) {
    int key  = a[x];
    a[x] = a[y];
    a[y] = key;
}

void Down(int a[], int i, int n) { // 最后结果就是大顶堆
    int parent = i;                    // 父节点下标
    int child  = 2 * i + 1;            // 子节点下标
    while (child < n) {
        if (child + 1 < n && a[child] < a[child + 1]) { // 判断子节点那个大，大的与父节点比较
            child++;
        }
        if (a[parent] < a[child]) { // 判断父节点是否小于子节点
            swap(a, parent, child);     // 交换父节点和子节点
            parent = child;                 // 子节点下标 赋给 父节点下标
        }
        child = child * 2 + 1; // 换行，比较下面的父节点和子节点
    }
}

void BuildHeap(int a[], int size) {
    for (int i = size / 2 - 1; i >= 0; i--) { // 倒数第二排开始, 创建大顶堆，必须从下往上比较
        Down(a, i, size);                 // 否则有的不符合大顶堆定义
    }
}

void HeapSort(int a[], int size) {
    BuildHeap(a, size); // 初始化堆
    display(a, size);   // 查看初始化结果
    for (int i = size - 1; i > 0; i--) 
    {
        swap(a, 0, i); // 交换顶点和第 i 个数据
        Down(a, 0, i); // 重新建立大顶堆
        display(a, size);
    }
}

int main() 
{
    int n,array[1001],i;
    cin>>n;
    for(i=0;i<n;i++)
        cin>>array[i];
    HeapSort(array,n);
    return 0;
}
