#include <vector>
#include<iostream>
#include<algorithm>

using namespace std;

const int N = 100010;

int n;
int q[N];

void quick_sort(int q[], int l, int r)
{
    if (l >= r)
        return;//��������ֻ��һ��������û����
    int x = q[(l + r) / 2], i = l - 1, j = r + 1;

    while (i < j)//ÿ����һ��whileѭ��
    {
        do i++;while (q[i] < x);
        do j--;while (q[j] > x);
        if (i < j) swap(q[i], q[j]);
    }
    quick_sort(q, l, j);
    quick_sort(q,j+1,r);
}

int main()
{
    cin >> n;

    for (int i = 0; i < n;i++)
        cin >> q[i];

    quick_sort(q, 0, n - 1);

    for (int i = 0;i < n;i++)
        cout << q[i]<<" ";

    return 0;
}


