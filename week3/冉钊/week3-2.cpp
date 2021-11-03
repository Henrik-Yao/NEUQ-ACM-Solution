#include<bits/stdc++.h>
using namespace std;
int visited[502]={0},a,b,flag=1,sum[502];//每一个start的路径都是子路径的和
vector<vector<int > >c;//记录命题关系；
int dfs(int d){
    if(visited[d]) return sum[d];
    if(d==b) return 1;
    if(c[d].empty()){
        flag=0;
        return 0;
    } 
    for(int i=0;i<c[d].size();i++){
        int temp=c[d][i];
        sum[d]+=dfs(temp);
    }
    visited[d]=1;
    return sum[d];
}
int main(){
    int n,m;
    cin>>n>>m;
    c.resize(n+1);
    while(m--){
     int s1,s2;
     cin>>s1>>s2;
     c[s1].push_back(s2);
    }
    cin>>a>>b;
    cout<<dfs(a)<<" ";
    if(flag) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}