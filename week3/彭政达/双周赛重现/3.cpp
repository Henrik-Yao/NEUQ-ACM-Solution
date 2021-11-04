#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
template <class T>
ll han(T n){
    if(n==1) return 2;
    return han(n-1)*3+2;
}
int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    ios::sync_with_stdio(false);
    while(cin>>n) cout<<han(n)<<endl;
    return 0;
}
