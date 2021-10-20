#include <iostream>
using namespace std;
typedef struct {
    int v;
    int t;
}Code;
int main(){
    int n,t;
    cin>>n>>t;
    Code f[n];
    for (int i = 0; i < n; ++i) {
        cin>>f[i].v>>f[i].t;
    }
    int sum = -100,x ;
    for (int i = 0; i < n; ++i) {
        if(f[i].t>t)x = f[i].v-f[i].t+t;
        else x = f[i].v;
        if(sum<x)sum = x;
    }
    cout<<sum;
    return 0;
}