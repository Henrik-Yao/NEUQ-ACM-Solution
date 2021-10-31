#include <bits/stdc++.h>
using namespace std;
bool visit[501]={0};//用来标记是否被访问
vector<int> mt[1000];//用来存储命题关系
int from,to,sum=0,flag=1,SUM[1000]={0};
int dfs(int start){
    if(visit[start]) {
        return SUM[start];
    }
    if(start==to) {
        return 1;
    }
    if(mt[start].empty()) {
        flag=0;
        return SUM[start];
    }
    int i;
    for(i=0;i<mt[start].size();i++){
        int a=mt[start][i];
        SUM[start]+=dfs(a);
    }
    visit[start]=1;
    return SUM[start];
}

int main(){
    int N,M;
    cin>>N>>M;
    while(M--){
        int b,c;
        cin>>b>>c;
        mt[b].push_back(c);
    }
    cin>>from>>to;
    cout<<dfs(from)<<" ";
    if(flag) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}
