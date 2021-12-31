#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 20010;

bool visited[N];
vector<int> nodes[N], res;

void dfs(int n) {
    visited[n] = true;
    res.push_back(n);
    for (auto & node : nodes[n]) if (!visited[node]) dfs(node);
}

int main()
{
    int n, e;
    cin >> n >> e;
    for (int i = 0; i < e; i++) {
        int a, b;
        cin >> a >> b;
        nodes[a].push_back(b);
    }
    for (auto & node : nodes) sort(node.begin(), node.end());
    for (int i = 0; i < n; i++) if (!visited[i]) dfs(i);
    for (auto & num : res) cout << num << " ";
    return 0;
}

