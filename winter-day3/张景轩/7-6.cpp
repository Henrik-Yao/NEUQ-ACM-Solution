#include <algorithm>
#include <iostream>
using namespace std;

typedef struct Edge
{
    int out;
    int in;
    int weight;
}Edge;

int f[201];

bool compare(Edge e1, Edge e2) 
{ 
    return e1.weight < e2.weight; 
}

void init() 
{
    for (int i=0;i<=200;i++) 
    {
        f[i] = i;
    }
}

int find(int x) 
{
    if (x == f[x])
    {
        return x;
    }
    return f[x] = find(f[x]);
}

int merge(int x, int y) 
{
    int a = find(x);
    int b = find(y);
    if(a != b) 
    {
        f[b] = a;
        return 1;
    }
    return 0;
}

int main() {
    int n, e;
    while (cin >> n >> e) 
    {
        Edge edge[e];
        init();
        for (int i = 0; i < e; i++) 
        {
            cin>>edge[i].out>>edge[i].in>>edge[i].weight;
        }
        sort(edge, edge + e, compare);

        int t = 0;
        int sum = 0;

        for (int i=0;i<e;i++) 
        {
            if (merge(edge[i].out, edge[i].in)) 
            {
                t++;
                sum += edge[i].weight;
            }
            if (t == n - 1)
            {
                break;
            }
        }
        if (t == n - 1)
        {
            cout << sum << endl;
        }
        else
        {
            cout << "There is no minimum spanning tree." << endl;
        }
    }
    return 0;
}