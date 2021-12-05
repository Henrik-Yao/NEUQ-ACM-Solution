#include<bits/stdc++.h>
using namespace std;
map<string,string>Q;
map<string,int>M;
int main(){
    int n,m;
    cin>>n>>m;
    string S,T;
    while(n--){
        cin>>S>>T;
        Q[T]=S;
        M[T]=1;
    }
    string A;
    while(m--){
        cin>>A;
        if(M[A])cout<<Q[A]<<endl;
        else cout<<"eh"<<endl;
    }
    return 0;
}
