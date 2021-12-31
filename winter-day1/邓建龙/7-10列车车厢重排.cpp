#include <bits/stdc++.h>
using namespace std;
const int N = 100;
queue<int> q[N];
int num = 1; // 表示队列数量
int n, x;
int main()
{
    cin >> n;
    for (int i = 0; i < N; i++) q[i].push(0);
    for (int i = 0; i < n; i++) {
        cin >> x;
        int flag1 = 1;
        for (int i = 0; i < num; i++) {
            if (q[i].back() > x) {
                q[i].push(x);
                flag1 = 0;
                break;
            }
        }
        if (flag1 == 1) {
            num++;
            q[num - 1].push(x);
        }
    }
    // num = ans + 1   ans = num - 1
    q[1].pop(); // 删除预先添加的 0
    int flag = 1;
    while (!q[1].empty()) {
        if (flag == 1) flag = 0, printf("%d", q[1].front());
        else printf(" %d", q[1].front());
        q[1].pop();
    }
    cout << endl;
    cout << num - 1 << endl;
    return 0;
}