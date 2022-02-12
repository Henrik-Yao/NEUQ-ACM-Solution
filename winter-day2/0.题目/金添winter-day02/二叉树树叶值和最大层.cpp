#include <bits/stdc++.h>
using namespace std;
//请谨记：叶结点指的是没有右子树和左子树的点！

int max_level = 0; //记录最大层数
int sum[1000];     //记录每一层的和
int exist[1000];   //记录每一层是否有叶子
struct tree
{
    int num;
    int level;
    tree *left;
    tree *right;
};
tree *treecreate(int level)
{
    tree *p = new tree;
    // int l=level;
    int num;
    cin >> num;
    if (num == 0)
    {
        p = NULL; //该节点到头
    }
    else
    {
        p->num = num;
        p->level = level;
        if (p->level > max_level)
        {
            max_level = p->level; //最深层数更新
        }
        p->left = treecreate(level + 1);
        p->right = treecreate(level + 1);
    }
    return p;
}
void runtree(tree *p)
{
    if (p == NULL)
        return;
    if (p->left == NULL && p->right == NULL)
    {
        sum[p->level] += p->num;
        exist[p->level]++;
    }
    runtree(p->left);
    runtree(p->right);
}
int main()
{
    tree *head = treecreate(0);
    runtree(head);
    int max1 = -1000;
    int call=-100;
    for (int i = 0; i <= max_level; i++)
    {
        if (exist[i] && sum[i] >= max1)
        {
            max1 = sum[i];
            call=i;
        }
    }
    cout<<call;
    return 0;
}