#include <iostream>
using namespace std;

class Node
{
public:
    Node *pointl, *pointr;
    int value;
    Node();
};
int mid[1000] = {}, after[1000] = {};
int find(int *, int, int);
Node *connect(int, int *a, int *b);
void pre(Node *);

main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> after[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> mid[i];
    }
    Node *point = connect(n, mid, after);
    pre(point);
}
int find(int *a, int x, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (a[i] == x)
            return i;
    }
    return 0;
}
Node::Node()
{
    pointl = pointr = NULL;
}
Node *connect(int n, int *a, int *b)
{
    if (n <= 0)
    {
        return NULL;
    }
    Node *nod = new Node;
    nod->value = b[n - 1];
    int t = find(a, b[n - 1], n);
    nod->pointl = connect(t, a, b);
    nod->pointr = connect(n - t - 1, a + t + 1, b + t);
    return nod;
}
void pre(Node *point)
{
    if (point == NULL)
        return;
    cout << point->value << " ";
    pre(point->pointl);
    pre(point->pointr);
}