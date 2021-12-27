#include <bits/stdc++.h>
using namespace std;
#define maxn 20010

struct graph{
    int u;
    int v;
    int w;
}g[maxn];

bool cmp(graph a,graph b){
    if(a.u == b.u)
    return a.v < b.v;
    return a.u < b.u;
}

int main(){
    int n,e;
    scanf("%d%d",&n,&e);
    for(int i = 0;i <e;i++){
        scanf("%d%d%d",&g[i].u,&g[i].v,&g[i].w);
    }
    sort(g,g + e,cmp);
    for(int i = 0,j = 0;i < e;i++){
        bool first = true,flag = false;
        while(g[j].u == i){
            if(first){
                printf("%d:",i);
                first = false;
                flag = true;
                }
            printf("(%d,%d,%d)",g[j].u,g[j].v,g[j].w);
            j++;
        }
        if(flag)puts("");
    }
    return 0;
}