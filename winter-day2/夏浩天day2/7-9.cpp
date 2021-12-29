#include <iostream>
using namespace std;

void getpre(int* a, int* b, int n)    //其中数组a为后序,b为中序,n为每次遍历数目
{
    if (n > 0)
    {
        int root = a[n - 1];  //根结点为后序遍历的最后一个
        int xb=0;
        for (int i = 0; i < n; i++)    //在中序遍历中查找根结点
            if (b[i] == root)
            {
                xb = i;
                break;
            }
        cout << root << " " ;
        getpre(a, b, xb);    //对左子树来查找根结点
        getpre(a + xb, b + xb + 1, n - xb - 1);  //对右子树来查找根结点
    }
}

int main()//原理是每次找出子树的根节点并分为更小的子树
{
    int n;
    cin >> n;
    int a[101], b[101];  //a[n]后序 b[n]中序
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];    //输入后序
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];    //输入中序
    }
    getpre(a, b, n);
    return 0;
}