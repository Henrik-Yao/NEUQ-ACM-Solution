#include<bits/stdc++.h>
using namespace std;
#define N 200
int m,n;
vector<int > num[N];
int v[N];
int sum = 0;
void bfs(int x)
{
    if(x==m){
        sum++;
        return;
    }
    for(int i = 1; i <= m; i++)
    {
        if(v[i]==0)
        {
            v[i] = 1;
            for (int y : num[i]) {
                v[y]--;
            }
            bfs(x+1);
            v[i] = 0;
            for (int y : num[i]) {
                v[y]++;
            }
        }
    }
}
int main() {
    while (cin>>m>>n) {
        sum = 0;
        for (int i = 0; i < m + 1; ++i) {
            v[i] = 0;
        }
        for(int i = 1; i <= m; i++)
        {
                num[i].clear();
        }
        for (int i = 1; i <= n; i++) {
            int a, b;
            cin >> a >> b;
            num[a].push_back(b);
            v[b]++;
        }
        bfs(0);
        if (sum >= 2)cout << 2;
        else cout << sum;
        cout<<endl;
    }
    return 0;
}