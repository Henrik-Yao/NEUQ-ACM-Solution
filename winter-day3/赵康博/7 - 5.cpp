#include<bits/stdc++.h>
using namespace std;
#define N 20000
typedef struct node{
    int jw;
    int length;
}node;
vector<node> p[N];
int main() {
    int max = 0;
    int n,m;
    cin>>n>>m;
    node q;
    for(int i = 0; i < m; i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        q.jw = b;
        q.length = c;
        p[a].push_back(q);
        q.jw = a;
        p[b].push_back(q);
    }
    int d[N],v[N];
    for(int i = 0; i <= n; i++){
        d[i] = 100000;
        v[i] = 0;
    }
    int l = p[1].size();
    for(int i = 0; i < l; i++)
    {
        if(d[p[1][i].jw]>p[1][i].length)d[p[1][i].jw] = p[1][i].length;
    }
    v[1] = 1;
    for(int i = 0; i < n - 1; i++)
    {
        int min = 1000;
        int min1;
        for (int j = 1; j <= n; ++j) {
            if(d[j]<min&&!v[j]){
                min = d[j];
                min1 = j;
            }
        }
        if(max<min)max = min;
        l = p[min1].size();
        for(int j = 0; j < l; j++)
        {
            if(d[p[min1][j].jw]>p[min1][j].length)d[p[min1][j].jw] = p[min1][j].length;
        }
        v[min1] = 1;
    }
    cout<<n-1<<" "<<max;
    return 0;
}