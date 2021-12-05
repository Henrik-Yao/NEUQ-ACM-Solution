#include<bits/stdc++.h>
using namespace std;
map<string,string>dic;
string trans,words,goal;
int main(){
    int n,m;
    cin>>n>>m;
    while(n--){
        cin>>trans>>words;
        dic[words]=trans;
    }
    while(m--){
        cin>>goal;
        if(dic[goal].size()!=0) cout<<dic[goal]<<endl;
        else cout<<"eh\n";
    }

    return 0;
}