#include <iostream>
#include <vector>
using namespace std;
vector<int> s[501];
bool p = true;
int cu[501];
int f,t;
int d(int n){
    int x = 0;
    if(cu[n]!=0)return cu[n];
    if(n == t)return 1;
    for (int i:s[n]) {
        x = x + d(i);
    }
    cu[n] = x;
    if(x==0)p = false;
    return x;
}
int main() {
    int n,m;
    cin>>n>>m;
    for (int i = 0; i < m; ++i) {
        int a,b;
        cin>>a>>b;
        s[a].push_back(b);
    }
    cin>>f>>t;
    int sum = d(f);
    cout<<sum<<" ";
    if(p)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}