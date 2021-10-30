#include<bits/stdc++.h>
using namespace std;
priority_queue<int>Q;
int main(){
    int n,T;
    cin>>n>>T;
    for(int i=0;i<n;i++){
        int v,t;
        cin>>v>>t;
        if(t>T)v=v-(t-T);
        Q.push(v);
    }
    printf("%d",Q.top());
    return 0;
}
