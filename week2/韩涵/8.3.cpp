/*#include<iostream>
using namespace std;

//根据菜鸟教程提供函数改编
template<typename T> //函数模板
void merge_sort(T arr[], int len) {
    T* a = arr;
    T* b = new T[len];//申请内存
    for (int seg = 1; seg < len; seg += seg) {//划分排序区间（一次排几个）
        for (int start = 0; start < len; start += seg + seg) {//排序起始位置
            int low = start, mid = min(start + seg, len), high = min(start + seg + seg, len);//将区间分为两段
            int k = low;//下标
            int start1 = low, end1 = mid;//前段
            int start2 = mid, end2 = high;//后段
            while (start1 < end1 && start2 < end2)//开始排序，从小到大
                b[k++] = a[start1] < a[start2] ? a[start1++] : a[start2++];//将两段中小的插在前面
            //将前/后段剩余数据顺序写入
            while (start1 < end1)
                b[k++] = a[start1++];
            while (start2 < end2)
                b[k++] = a[start2++];
        }
        //将最新排序的指针换为a，另一区域换为b
        T* temp = a;
        a = b;
        b = temp;
    }
    //最后将arr段替换为排好的顺序，并使a指向它
    if (a != arr) {
        for (int i = 0; i < len; i++)
            b[i] = a[i];
        b = a;
    }
    //清除b的内存
    delete[] b;
}

int main() {
    int a;
    int ans[99];
    cin >> a;
    for (int i = 0; i < a; i++) cin >> ans[i];
    merge_sort(ans, a);//归并排序
    for (int i = 0; i < a; i++) cout << ans[i] << " ";
}*/