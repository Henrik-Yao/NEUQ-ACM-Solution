#include <bits/stdc++.h>
using namespace std;

map<string,string>m;
int N,M;
int main(){
    cin>>N>>M;
    for(int i = 0;i < N;i++){
        string p,q;
        cin>>p;
        cin>>q;
        m[q] = p;
    }
    for(int i  = 0 ;i < M;i++){
        string s;
        cin>>s;
        if(!m.count(s))
        puts("eh");
        else
        cout<<m[s]<<endl;
    }
    return 0;
}