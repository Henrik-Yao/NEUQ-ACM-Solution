#include <bits/stdc++.h>
using namespace std;

int main(){
    map <string,string> node;
    int m,n;
    cin>>m>>n;
    for(int i = 0 ; i < m ; i++){
        string a,b;
        cin>>a>>b;
        node[b] = a;
    }
    for(int i = 0; i < n ; i++){
        string t;
        cin>>t;
        if(node[t]!=""){
            cout<<node[t]<<endl;
        }
        else cout<<"eh"<<endl;
    }
    return 0;
}