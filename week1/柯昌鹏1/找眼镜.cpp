#include <bits/stdc++.h>
using namespace std;
struct ll{int pos;char p[101];}d[100001];
int main(){
    int n,m,pos=1,a,b;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    scanf("%d%s",&d[i].pos,d[i].p);
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d",&a,&b);
        if(a!=d[pos].pos){pos+=b;}
        else if(a==d[pos].pos){pos-=b;}
        if(pos>=n) pos%=n;
        else while(pos<=0) pos+=n;
    }
    cout<<d[pos].p;
    return 0;
}
