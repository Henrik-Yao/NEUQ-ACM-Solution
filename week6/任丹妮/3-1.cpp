#include <bits/stdc++.h>
#define maxn 100
using namespace std;
int main(){
    int n,m,q;
    int num=0,count=1;
    bool visit[maxn];
    cin>>n>>m>>q;
    memset(visit,0,sizeof(visit));
    for(int i=q;count<n;i++){
        if(i>n) i=i%n;
        if(!visit[i]) {
            num++;
        }
        else {
            continue;
        }
        if(num==m){
            num=0;
            visit[i]=1;
            count++;
            continue;
        }
    }
    for(int i=1;i<=n;i++){
        if(visit[i]==0) {
            cout<<i<<endl;
            break;
        }
    }
    printf("姓名：任丹妮 学号：202010014\n");
    return 0;
}