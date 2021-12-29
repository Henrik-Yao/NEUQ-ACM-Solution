/*
7-2 图的删边操作
请编写程序对给定的有向图删除若干条边。有向图中包含n个顶点，编号为0至n-1。
输入格式:
输入第一行为两个正整数n和e，分别表示图的顶点数和边数，其中n不超过20000，e不超过1000。
接下来e行表示每条边的信息，每行为3个非负整数a、b、c，其中a和b表示该边的端点编号，
c表示权值。各边并非按端点编号顺序排列。随后一行为一个整数k，表示删除的边的条数，
接下来k行，每行为2个非负整数a、b，表示待删除的边为a->b。保证删除的边一定在原图中。
输出格式:
输出执行删边操作之后的图。每行表示一个顶点引出的所有边，格式为a:(a,b,w)……，
表示有向边a->b的权值为w，a引出的多条边按编号b的递增序排列。若某顶点没有引出边，则不输出。
输入样例:
7 7
0 1 5
0 3 7
0 6 6
1 2 4
2 5 1
3 5 3
6 5 4
2
2 5
0 1
输出样例:
0:(0,3,7)(0,6,6)
1:(1,2,4)
3:(3,5,3)
6:(6,5,4)
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    int vertex,edge,a,b,c,n;
    freopen("in2.txt","r",stdin);
    ios::sync_with_stdio(false);
    cin>>vertex>>edge;
    map<int,map<int,int> > mp;
    for(int i=0;i<edge;i++){
        cin>>a>>b>>c;
        mp[a][b]=c;
    }
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a>>b;
        mp[a].erase(b);
    }
    for(auto i:mp){
        int a=i.first;
        cout<<a<<":";
        for(auto j:i.second) cout<<s"("<<a<<","<<j.first<<","<<j.second>>")";
        cout<<endl;
    }
}
