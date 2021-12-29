#include <iostream>
using namespace std;
typedef struct tr
{
    int data;
    tr* left = NULL;
    tr* right = NULL;
}tr;
int a[120], r[120];
tr* x = new tr;
tr* by(int l1, int r1, int l2, int r2)
{
    tr* t = new tr;
    if (l1 > r1 || l2 > r2)
        return NULL;
    else if (l1 == r1 && r2 == l2)
    {
        t->data = a[l1];
        t->left = NULL;
        t->right = NULL;
    }
    else
    {
        int root = a[l1];
        t->data = root;
        int i;
        for (i = l2; i <= r2; i++)
        {
            if (r[i] == root)
            {
                break;
            }
        }
        if (i == l2)
        {
            t->right = by(l1 + i + 1 - l2, r1, i + 1, r2);
        }
        else if (i == r2)
        {
            t->left = by(l1 + 1, i + l1 - l2, l2, i - 1);
        }
        else
        {
            t->left = by(l1 + 1, l1 + i - l2, l2, i - 1);
            t->right = by(l1 + i + 1 - l2, r1, i + 1, r2);
        }
    }
    return t;

}
void dy(tr* p)
{
    if (p != NULL)
    {
        dy(p->left);
        dy(p->right);
        cout << p->data << " ";
    }
}
int main()
{
    int n;
    int i;
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (i = 0; i < n; i++)
    {
        cin >> r[i];
    }
    tr* p = by(0, n - 1, 0, n - 1);
    dy(p);
}
