#include<bits/stdc++.h>
using namespace std;
const int k = 2e5+10;
int cnt = 0;
int head[k];

struct t{
    int a,b,c;
}f[k];

bool cmp(t x,t y){
    if(x.a == y.a){
        return x.b > y.b;
    }
    return x.a < y.a;
}

struct Edge{
    int next,to,weight;
}edge[k];

void init(int n) {
    for(int i=0; i<n; ++i) 
        head[i] = -1;  // head³õÊ¼¶¼Îª-1
    cnt = 0;
};

void add(int u,int v,int w)
{
    edge[cnt].weight = w;
    edge[cnt].to = v;
    edge[cnt].next = head[u];
    head[u] = cnt++;
}

int main(){
    int n,e;
    cin >> n >> e;
    init(n);
    for(int i=0; i<e; i++){
        cin >> f[i].a >> f[i].b >> f[i].c;
    }
    sort(f,f+e,cmp);
    int dele;
    cin >> dele;
    for(int i=1; i<=dele; i++){
        int a,b;
        cin >> a >> b;
        for(int i=0; i<e; i++){
            if(f[i].a == a && f[i].b == b){
                f[i].a = f[i].b = f[i].c = -1;
            }
        }
    }
    for(int i=0; i<e; i++){
        if(f[i].a == -1 && f[i].b == -1 && f[i].c == -1)    continue;
        add(f[i].a,f[i].b,f[i].c);
    }
    for(int i=0; i<n; i++){
        if(head[i] == -1)   continue;
        printf("%d:",i);
        for(int j=head[i]; j!=-1; j=edge[j].next){
            printf("(%d,%d,%d)",i,edge[j].to,edge[j].weight);
        }
        cout << "\n";
    }
}
