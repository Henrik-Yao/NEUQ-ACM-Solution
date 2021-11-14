#include <iostream>
#include <cstring>
using namespace std;
const int N = 1e6 + 10;
struct body{
    int father = -1, mother = -1;
    char gender;
}bodys[N];
int n, k, one, two, flag;
int vis[N];

void dfs(int uid, int now) {
    if (vis[uid] == 1) {
        flag = 1;
        return;
    }
    vis[uid] = 1;
    if (now >= 5) return;
    if (bodys[uid].father != -1) dfs(bodys[uid].father, now + 1);
    if (bodys[uid].mother != -1) dfs(bodys[uid].mother, now + 1);
}

int main()
{
    cin >> n;
    int uid;
    for (int i = 0; i < n; i++) {
        scanf("%d", &uid);
        cin >> bodys[uid].gender >> bodys[uid].father >> bodys[uid].mother;
        bodys[bodys[uid].father].gender = 'M';
        bodys[bodys[uid].mother].gender = 'F';
    }
    cin >> k;
    int start = 1;
    while (k--) {
        cin >> one >> two;
        if (bodys[one].gender == bodys[two].gender) {
            start == 1 ? start = 0, cout << "Never Mind" : cout << endl << "Never Mind";
            continue;
        }
        memset(vis, 0, sizeof vis);
        flag = 0;
        dfs(one, 1), dfs(two, 1);
        start == 1 ? start = 0, flag == 1 ? cout << "No" : cout << "Yes" : flag == 1 ? cout << endl << "No" : cout << endl << "Yes";
    }
    return 0;
}

