#include<bits/stdc++.h>
using namespace std;
const int k=1e6+5;
int main(){
    int n,m;
    cin>>n>>m;
    int a;
    for(int i=1;i<=n;i++){
        cin>>a;
        if(a>=m){
            cout<<i;
            return 0;
        }
    }
    cout<<n+1;
    return 0;
}
