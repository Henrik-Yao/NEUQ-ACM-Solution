#include<bits/stdc++.h>
using namespace std;
struct P{
    int num1;
    int num2;
};
int main(){
    int N,M;
    cin>>N>>M;
    struct P a[M+1];
    for(int i=1;i<=M;i++){
          cin>>a[i].num1>>a[i].num2;
    }
    int x;
    cin>>x;
    while(x--){
             int n;
             cin>>n;
        int vis[N+1];
        for(int i=1;i<=N;i++){
            vis[i]=0;
        }
        for(int i=0;i<n;i++){
            int b;
             cin>>b;
            vis[b]=1;
        }
        int i=1;
        for(;i<=M;i++){
        if(vis[a[i].num1]!=1&&vis[a[i].num2]!=1)break;
        }
    if(i==M+1)printf("YES\n");
    else printf("NO\n");
        }
    return 0;
}
