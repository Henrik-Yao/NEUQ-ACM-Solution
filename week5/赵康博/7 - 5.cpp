#include <iostream>

using namespace std;
int m[50000];
int n;
int v[50000];
int t = 0;
void f(int x){
    v[x] = 1;
    if(m[x]==0){
        t = 1;
        return;
    }
    if(x+m[x]<n&&v[x+m[x]]==0)f(x+m[x]);
    if(x-m[x]>=0&&v[x-m[x]]==0)f(x-m[x]);
}
int main(){
    cin>>n;
    for (int i = 0; i < n; ++i) {
        cin>>m[i];
    }
    int s;
    cin>>s;
    f(s);
    if(t==1)cout<<"True";
    else cout<<"False";
    return 0;
}