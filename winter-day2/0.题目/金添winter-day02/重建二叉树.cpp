#include <bits/stdc++.h>
using namespace std;
struct tree
{
    char ch;
    int level;
    tree *left;
    tree *right;
};
bool judge(string m, string b)
{
    if (m.length() == 0 && b.length() == 0)
    {
        return true;
    }
    if (m.length() != b.length())
    {
        return false;
    }
    int i;
    char ch = m[m.length() - 1];
    for (i = 0; i < b.length(); i++)
    {
        if (ch == b[i])
        {
            break;
        }
    }
    string mleft = m.substr(0, i);
    string mright = m.substr(i, m.length() - 1 - i);
    string bleft = b.substr(0, i);
    string bright = b.substr(i + 1);
    for (i = 0; i < mleft.length(); i++)
    {
        if (bleft.find(mleft[i]) == -1)
        {
            return false;
        }
    }
    for (i = 0; i < mright.length(); i++)
    {
        if (bright.find(mright[i]) == -1)
        {
            return false;
        }
    }
    return judge(mleft, bleft) && judge(mright, bright);
} // 判断是否可合法的函数
tree *create(char mid[], char post[], int len, int level, int &flag)
{
    if (!len)
        return NULL;
    int index = 0;
    char root = post[len - 1];
    for (index = 0; mid[index] != root; index++);
        
    tree *p = new tree;
    p->ch = root;
    p->level = level;
    if (p->level > flag)
        flag = p->level; //最高阶更新
    p->right = create(mid + index + 1, post + index, len - index - 1, level + 1, flag);
    p->left = create(mid, post, index, level + 1, flag);
    return p;
}
void run(tree *head)
{
    if (head == NULL)
        return;
    cout << head->ch;
    run(head->left);
    run(head->right);
}
int main()
{
    char post[30];
    char mid[30];
    while (cin >> post)
    {
        cin >> mid;
        string remp1,remp2;
        remp1+=post;
        remp2+=mid;
        if (judge(remp1, remp2))
        {
            int flag = 0;
            int len = strlen(mid);
            tree *head = new tree;
            head = create(mid, post, len, 0, flag);
            cout << flag << endl;
            run(head);
            cout << endl;
        }
        else
            cout << "INVALID" << endl;
    }

    return 0;
}