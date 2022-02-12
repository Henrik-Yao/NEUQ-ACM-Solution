#include <bits/stdc++.h>
using namespace std;
//����ǣ�Ҷ���ָ����û�����������������ĵ㣡

int max_level = 0; //��¼������
int sum[1000];     //��¼ÿһ��ĺ�
int exist[1000];   //��¼ÿһ���Ƿ���Ҷ��
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
        p = NULL; //�ýڵ㵽ͷ
    }
    else
    {
        p->num = num;
        p->level = level;
        if (p->level > max_level)
        {
            max_level = p->level; //�����������
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