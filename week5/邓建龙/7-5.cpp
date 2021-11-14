#include <iostream>

using namespace std;

const int N = 5e4 + 10;

bool vis[N];
int nums[N];
int n, start;
int whe = 0;

void dfs(int idx) {
    if (nums[idx] == 0) {
        whe = 1;
        return;
    }
    int next1 = idx - nums[idx], next2 = idx + nums[idx];
    if (next1 >= 0 && !vis[next1]) {
        vis[next1] = true;
        dfs(next1);
    }
    if (next2 < n && !vis[next2]) {
        vis[next2] = true;
        dfs(next2);
    }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++) cin >> nums[i];
    cin >> start;
    vis[start] = true;
    dfs(start);
    if (whe == 1) {
        cout << "True";
    } else {
        cout << "False";
    }
    return 0;
}

