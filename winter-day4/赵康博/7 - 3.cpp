#include<bits/stdc++.h>
using namespace std;
#define N 50005
typedef struct node{
    int jw;
    long long length;
}node;
int v[N];
node d[N];
vector<node> p[500005];
int main() {
    int n,m;
    while (cin>>n>>m) {
        node q;
        for(int i = 0; i <= n; i++)p[i].clear();
        for (int i = 0; i < m / 2; i++) {
            int a, b, c;
            cin >> a >> b >> c;
            q.jw = b;
            q.length = c;
            p[a].push_back(q);
            q.jw = a;
            p[b].push_back(q);
        }
        for (int i = 0; i <= n; i++) {
            d[i].length = 1e17;
            v[i] = 0;
        }
        int y,w;
        cin>>y>>w;
        if(y==w){
            printf("%d-->%d:0",y,y);
            return 0;
        }
        int l = p[y].size();
        for (int i = 0; i < l; i++) {
            if (d[p[y][i].jw].length > p[y][i].length){
                d[p[y][i].jw].length = p[y][i].length;
                d[p[y][i].jw].jw = y;
            }
        }
        v[y] = 1;
        for (int i = 0; i < n - 1; i++) {
            long long min = 1e17;
            int min1;
            for (int j = 0; j < n; ++j) {
                if (d[j].length < min && !v[j]) {
                    min = d[j].length;
                    min1 = j;
                }
            }
            l = p[min1].size();
            for (int j = 0; j < l; j++) {
                if (d[p[min1][j].jw].length > d[min1].length + p[min1][j].length)
                {
                    d[p[min1][j].jw].length = p[min1][j].length + d[min1].length;
                    d[p[min1][j].jw].jw = min1;
                }
            }
            v[min1] = 1;
        }
        int j = w;
        stack<int> s;
        while (j!=y)
        {
            s.push(j);
            j = d[j].jw;
        }
        s.push(y);
        int siz = s.size();
        for(int i = 0; i < siz; i++)
        {
            if(i==0){
                cout<<s.top();
                s.pop();
            } else {
                cout<<"-->"<<s.top();
                s.pop();
            }
        }
        cout<<":"<<d[w].length<<endl;
    }
    return 0;
}