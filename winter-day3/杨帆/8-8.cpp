#include<iostream>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;

const int N = 1000;
int n, m, G[N][N], in[N];
int ans = 0;

void toposort() {
    int cnt = 0;
    queue<int> que;
    for (int i = 1; i <= n; i++) {
        if (in[i] == 0)que.push(i);
    }
    while (!que.empty()) {
        if (que.size() > 1)
            ans = 2;
        int temp = que.front(); 
        que.pop();
        cnt++;
        for (int i = 1; i <= n; i++) 
			if (G[temp][i]) {
            	in[i]--;
            	if (in[i] == 0)
					que.push(i);
        	}
    }
    if (n == cnt) {
        if (!ans)
            ans = 1;
    }
    else ans = 0;
}

int main() {
    while (cin >> n >> m) {
        ans = 0;
        memset(G, 0, sizeof(G));
        memset(in, 0, sizeof(in));
        for (int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;
            G[a][b] = 1;
            in[b]++;
        }
        toposort();
        cout << ans << endl;
    }
}
