#include <iostream>
#include<list>
using namespace std;

list<int> q;
void last(int* a, int* b, int n, int cs)
{
    if (n > 0)
    {
        int root = a[0];//根为先序遍历第一位
        int xb = 0;
        for(int i=0;i<n;i++)
            if (b[i] == root)
            {
                xb = i; break;
            }
        q.push_back(root);
        //左边有xb个节点
        last(a + xb + 1, b + xb + 1, n - xb - 1, cs + 1);//右
        last(a + 1, b, xb, cs + 1);//左
    }
}

int main()//原理是每次找出子树的根节点并分为更小的子树
{
    int cs = 0;
    int n;
    cin >> n;
    int a[101], b[101];  //a[n]先序 b[n]中序
    for (int i = 0; i < n; i++)cin >> a[i];
    for (int i = 0; i < n; i++)cin >> b[i];
    last(a, b, n, cs);

    while (!q.empty())
    {
        cout << q.back() << " ";
        q.pop_back();
    }
}