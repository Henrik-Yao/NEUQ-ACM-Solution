#include <bits/stdc++.h>
using namespace std;

bool v[10010];
int ans[10010];
int cnt;
void prime(int l,int r){
    cnt = 0;
    memset(ans,0,sizeof(ans));
    memset(v,0,sizeof(v));
    for(int i = 2;i <= r;i++){
        if(v[i])continue;
        for(int j = i;j <= r / i;j++){
        v[i * j] = 1;
        }
        if(i >= l && i <= r)
        ans[cnt++] = i;
    }
}

int main(){
    int a,b;
    while(cin>>a>>b){
    prime(a,b);
    for(int k = 0;k < cnt - 1;k++){
        cout<<ans[k]<<" ";
    }
    cout<<ans[cnt - 1];
    puts("");
    }
    return 0;
}