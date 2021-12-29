#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int _=2e3+7;
int read() {
    int x=0,f=1;char s=getchar();
    for(;s>'9'||s<'0';s=getchar()) if(s=='-') f=-1;
    for(;s>='0'&&s<='9';s=getchar()) x=x*10+s-'0';
    return x*f;
}
int n,m,A,B,C,dis[_][_],a[_][_]; 
int main() {
    n=read();m=read();
    memset(a,-1,sizeof(a));
    memset(dis,0x3f,sizeof(dis));
    for(int i=0;i<m;i++) {
        A=read(),B=read(),C=read();
        dis[A][B]=C,a[A][B]=C;
    }
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) for(int k=0;k<n;k++) {
        if(i==k||i==j||j==k) continue;
        if(dis[j][k]>dis[j][i]+dis[i][k]) dis[j][k]=dis[j][i]+dis[i][k];
    }
    for(int i=1;i<=2;i++) {
        A=read(),B=read();int v=dis[A][B];
        if(v>1e9) v=-1;
        if(A==B) v=0;
        cout<<A;
        while(233) {
            int pd=0;
            for(int j=0;j<n;j++)
            if(dis[A][j]+dis[j][B]==dis[A][B]&&a[A][j]!=-1) {
                printf("->%d",A=j),pd=1;
                break;
            }
            if(pd==0) break;
        }
        cout<<"->"<<B<<":"<<v<<"\n";
    }
    int ma=0;
    for(int i=0;i<n;i++) {
        for(int j=i+1;j<n;j++) {
            if(dis[i][j]>1e9) continue;
            if(dis[i][j]>ma) ma=dis[A=i][B=j];
        }
    }
    cout<<A;
    int v=dis[A][B];
    while(233) {
        int pd=0;
        for(int j=0;j<n;j++)
        if(dis[A][j]+dis[j][B]==dis[A][B]&&a[A][j]!=-1) {
            A=j,cout<<"->"<<A,pd=1;
            break;
        } if(pd==0) break;
    }
    cout<<"->"<<B<<":"<<v<<"\n";
    return 0;
}
