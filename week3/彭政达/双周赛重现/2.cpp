#include <bits/stdc++.h>
using namespace std;
string A,B,C;
template <class T>
void han(int n,T A,T B,T C){
    if(n==1) cout<<A<<"->"<<C<<endl;
    if(n>=2){
        han(n-1,A,C,B);
        cout<<A<<"->"<<C<<endl;
        han(n-1,B,A,C);
    }
}
int main(){
    int n;
    ios::sync_with_stdio(false);
    cin>>n>>A>>B>>C;
    han(n,A,B,C);
    return 0;
}
