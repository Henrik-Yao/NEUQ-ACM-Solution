#include <bits/stdc++.h>
using namespace std;
int n,m,pos=1,a,b;
struct ll{
    int pos;char p[101];
}d[1000001];
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        scanf("%d%s",&d[i].pos,d[i].p);
    for(int i=1;i<=m;i++){
        cin>>a>>b;
        if(a==d[pos].pos){
            pos=(pos-b+n-1)%n+1;continue;
        }
        if(a!=d[pos].pos){pos=(pos+b-1)%n+1;continue;}
    }
    cout<<d[pos].p;
    return 0;
}
