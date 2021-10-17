#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;
bool compare(int a, int b)
{
    return a > b;
}
int main()
{
    int n, t;
    cin >> n >> t;
    int a[100000], b[100000], c[100000];//快乐值，用餐时间，终止
    for (int i = 0;i < n;i++)
    {
        cin >> a[i] >> b[i];
        if (b[i] > t)
            c[i] = a[i] + t - b[i];
        else
            c[i] = a[i];
    }
    sort(c, c + n, compare);
    cout << c[0];
}
