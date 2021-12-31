#include <iostream>
#include <algorithm>
using namespace std;
struct edge{
    int p1,p2;
    int w;
};
int father[20005];
edge e[20005];
int _rank[20005];
bool cmp(edge e1,edge e2){
    if(e1.w!=e2.w) return e1.w<e2.w;
    else return e1.p1<e2.p2;
}
int find_father(int x){
     return father[x]==x?x:father[x]=find_father(father[x]);
}
int main(){
    int vertices,edges;
    cin >> vertices >> edges;
    int n1,n2,n3;
    for(int i=0;i<edges;i++){
        cin >> e[i].p1 >> e[i].p2 >> e[i].w;
        father[e[i].p1]=e[i].p1;
        father[e[i].p2]=e[i].p2;
        _rank[e[i].p1]=1;
        _rank[e[i].p2]=1;
    }
    sort(e,e+edges,cmp);
    int in_line=0;
    int max_w=0;
    for(int i=0;i<edges,in_line<vertices-1;i++){
        int f1=find_father(e[i].p1);
        int f2=find_father(e[i].p2);
        if(f1!=f2){
            if(_rank[f1]<_rank[f2]) father[f1]=f2;
            else if(_rank[f2]<_rank[f1]) father[f2]=f1;
            else{
                father[f1]=f2;
                _rank[f2]++;
            }
            in_line++;
            if(e[i].w>max_w) max_w=e[i].w;
        }
    }
    cout <<vertices-1 << " " <<  max_w << endl;
}