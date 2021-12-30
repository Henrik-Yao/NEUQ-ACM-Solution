#include <iostream>
#include <map>
using namespace std;
class Node
{
public:
    int value;
    map<int, int> connection; //节点对边权值的索引
};
main()
{
    int n, e;
    cin >> n >> e;
    Node list[n];
    for (int i = 0; i < e; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        list[a].value = a;
        list[a].connection[b] = c;
    }
    int x;
    cin >> x;
    for (int i = 0; i < x; i++)
    {
        int a, b;
        cin >> a >> b;
        list[a].connection.erase(b);
    }
    for (int i = 0; i < n; i++)
    {
        if (!list[i].connection.empty())
        {
            cout << i << ':';
            for (auto j = list[i].connection.begin(); j != list[i].connection.end(); j++)
            {
                cout << '(' << i << ',' << j->first << ',' << j->second << ')';
            }
            cout << endl;
        }
    }
}