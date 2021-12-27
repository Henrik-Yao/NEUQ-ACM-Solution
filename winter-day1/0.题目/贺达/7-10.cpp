#include<bits/stdc++.h>
using namespace std;
queue<int> que[100];
int main() {
    int ans = 0;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        bool flag = false;
        for (int j = 0; j < ans; j++)
        {
            if (que[j].back() > a)
            {
                que[j].push(a);
                flag = true;
                break;
            }
        }
        if (!flag) {
            que[ans].push(a);
            ans++;
        }
    }
    for (int i = 0; i < ans; i++)
    {
        if (que[i].back() == 1)
        {
            while (!que[i].empty())
            {
                cout << que[i].front();
                que[i].pop();
                if (!que[i].empty()) cout << ' ';
                else cout << endl;
            }
            break;
        }
    }
    cout << ans;
    return 0;
}
