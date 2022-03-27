#include <iostream>
#include <queue>
using namespace std;

class Node
{
public:
    Node *pointl, *pointr;
    int value;
    Node();
};

int mid[1009], pre[1009];
int find(int *, int, int);
Node *connect(int, int *, int *);

main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> pre[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> mid[i];
    }
    Node *point = connect(n, mid, pre);
    queue<Node *> list;
    list.push(point);
    while (!list.empty())
    {
        Node *node = list.front();
        list.pop();
        cout << node->value << " ";
        if (node->pointl)
        {
            list.push(node->pointl);
        }
        if (node->pointr)
        {
            list.push(node->pointr);
        }
    }
}
int find(int *a, int x, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (a[i] == x)
        {
            return i;
        }
    }
    return 0;
}
Node *connect(int n, int *a, int *b)
{
    if (n <= 0)
        return NULL;
    Node *x;
    x = new Node;
    x->value = b[0];
    int t = find(a, b[0], n);
    x->pointl = connect(t, a, b + 1);
    x->pointr = connect(n - t - 1, a + t + 1, b + t + 1);
    return x;
}
Node::Node()
{
    pointl = pointr = NULL;
}