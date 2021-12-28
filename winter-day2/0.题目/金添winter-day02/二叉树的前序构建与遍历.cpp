#include <bits/stdc++.h>
using namespace std;
int max_level = 0; //记录最大层数
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
    if(p==NULL)
    return;
    cout<<p->num;
    runtree(p->left);
    runtree(p->right);
}
int main()
{
    tree *head = treecreate(0);
    runtree(head);
    return 0;
}