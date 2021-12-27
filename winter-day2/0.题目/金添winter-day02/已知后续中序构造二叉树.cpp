#include <bits/stdc++.h>
using namespace std;
struct tree
{
    int num;
    tree *left;
    tree *right;
};
void fro_create(int mid[], int post[], int len)
{
    if (!len)
        return;
    int index = len - 1;
    int root = post[len - 1]; //根节点
    for (index = len - 1; root != mid[index]; index--);
    //获取中央节点的下标
    cout << root << " ";
    fro_create(mid, post, index);
    fro_create(mid + index + 1, post + index, len - index - 1); // 注：此处post数组地址无需加1！
}
int main()
{
    int len;
    cin >> len;
    int mid[100];
    int post[100];
    for (int i = 0; i < len; i++)
        cin >> post[i];
    for (int i = 0; i < len; i++)
        cin >> mid[i];
    fro_create(mid, post, len);
    return 0;
}