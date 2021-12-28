#include <bits/stdc++.h>
using namespace std;
struct Edge{
    int t;
    int h;
    int w;
};
bool cmp(Edge x,Edge y){
    return x.w<y.w;
}
int f[1001];
int find(int x){
    if(x==f[x]) return x;
    else return f[x]=find(f[x]);
}
bool union_set(int x, int y) {
    int a = find(x);
    int b = find(y);
    if (a != b) {
        f[b] = a;
        return true;
    }
    return false;
}
int main(){
    int n,e;
    cin>>n>>e;
        Edge edge[e];
        for(int i=0;i<=1001;i++)
        {
            f[i]=i;
        }
        for(int i=0;i<e;i++)
        {
            cin>>edge[i].t>>edge[i].h>>edge[i].w;
            
        }
        sort(edge,edge+e,cmp);
        int node=0,Max=-999;
        for(int i=0;i<e;i++){
            if(union_set(edge[i].t,edge[i].h)){
                node++;
                Max=max(Max,edge[i].w);
            }
            if(node==n-1)
                break;
        }
        cout<<node<<" "<<Max<<endl;    
    return 0;
}
