#include <bits/stdc++.h>
using namespace std;
#define N 20010
struct node{
    int adj;
    int w;
};
vector<node>AG[N];
bool  cmp(node a,node b)
{
        return a.adj<b.adj;

}
int main(){
    int n,e;
    cin>>n>>e;
    while(e--){
        int t,h,v;
        cin>>t>>h>>v;
        node a;
        a.adj=h;
        a.w=v;
        AG[t].push_back(a);
    }
    for(int i=0;i<n;i++){
        if(AG[i].size()==0)
            continue;
        sort(AG[i].begin(), AG[i].end(),cmp);
        cout<<i<<":";
         for (int ptr = 0; ptr != AG[i].size(); ptr ++)
            cout<<"("<<i<<","<<AG[i][ptr].adj<<","<<AG[i][ptr].w<<")";
        cout<<endl;
    }
        return 0;
}
