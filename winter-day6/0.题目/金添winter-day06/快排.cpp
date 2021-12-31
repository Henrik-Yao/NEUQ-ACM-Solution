#include <bits/stdc++.h>
using namespace std;
int a[1000];
int num;
void quick_sort(int left, int right)
{
    if (left >= right)
        return; //直接退出
    int key = a[left];
    int l = left;
    int r = right;
    while (l < r)
    {
        while (a[r] >= key && l < r)
            r--;
        while (a[l] <= key && l < r)
            l++;
        if (r > l)
        {
            swap(a[l], a[r]);
        }
    }
    swap(a[l], a[left]); // key值和i，j相遇点交换
    // for (int i = 0; i < num; i++)
    //     cout << a[i] << " ";
    // cout << endl;
    quick_sort(left, l - 1);
    quick_sort(l + 1, right);
}
int main()
{
    cin >> num;
    for (int i = 0; i < num; i++)
        cin >> a[i];
    quick_sort(0, num - 1);
    for (int i = 0; i < num ; i++)
        cout << a[i] << endl;
    // cout << endl;
    return 0;
}