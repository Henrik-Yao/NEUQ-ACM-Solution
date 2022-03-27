#include <bits/stdc++.h>
using namespace std;
map<string,string>d;
int main(){
    int N,M;
    cin>>N>>M;
    while(N--){
        string a,b;
        cin>>a>>b;
        d[b]=a;
    }
    while(M--){
        string c;
        cin>>c;
        if(d[c]!="") cout<<d[c]<<endl;
        else cout<<"eh"<<endl;
    }
    return 0;
}
