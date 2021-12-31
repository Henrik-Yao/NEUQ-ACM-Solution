#include <iostream>
#include<algorithm>
#include <iostream>
using namespace std;
int a[1000];
int num;
void qsor(int left, int right)
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
            swap(a[l], a[r]);
    }
    swap(a[l], a[left]);
    qsor(left, l - 1);
    qsor(l + 1, right);
}
int main()
{
    cin >> num;
    for (int i = 0; i < num; i++)
        cin >> a[i];
    qsor(0, num - 1);
    for (int i = 0; i < num; i++)
        cout << a[i] << endl;
    return 0;
}
