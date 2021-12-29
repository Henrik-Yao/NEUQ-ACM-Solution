#include<bits/stdc++.h>
using namespace std;
#define N 20000
typedef struct node{
    int jw;
    int length;
}node;
vector<node> p[N];
int main() {
    int n,m;
    while (cin>>n>>m) {
        int max = 0;
        node q;
        for(int i = 0; i <= n; i++)p[i].clear();
        for (int i = 0; i < m; i++) {
            int a, b, c;
            cin >> a >> b >> c;
            q.jw = b;
            q.length = c;
            p[a].push_back(q);
            q.jw = a;
            p[b].push_back(q);
        }
        int d[N], v[N];
        for (int i = 0; i <= n; i++) {
            d[i] = 100000;
            v[i] = 0;
        }
        int l = p[1].size();
        for (int i = 0; i < l; i++) {
            if (d[p[1][i].jw] > p[1][i].length)d[p[1][i].jw] = p[1][i].length;
        }
        v[1] = 1;
        for (int i = 0; i < n - 1; i++) {
            int min = 100000;
            int min1;
            for (int j = 1; j <= n; ++j) {
                if (d[j] < min && !v[j]) {
                    min = d[j];
                    min1 = j;
                }
            }
            max+=min;
            l = p[min1].size();
            for (int j = 0; j < l; j++) {
                if (d[p[min1][j].jw] > p[min1][j].length)d[p[min1][j].jw] = p[min1][j].length;
            }
            v[min1] = 1;
        }
        if(max<10000)
        cout <<max<<endl;
        else cout<<"There is no minimum spanning tree."<<endl;
    }
    return 0;
}