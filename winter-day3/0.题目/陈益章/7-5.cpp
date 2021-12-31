#include<iostream>
#include<cstring>
using namespace std;
int g[310][310];
int n,m,a,b,c,minn[310],mmax=-1;
bool u[310];
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;++i){
        scanf("%d%d%d",&a,&b,&c);
        g[a][b]=c;
        g[b][a]=c;
    }
    memset(minn,1,sizeof(minn));    
    minn[1]=0;
    memset(u,1,sizeof(u));
    for(int i=1;i<=n;++i){
        int k=0;
        for(int j=1;j<=n;j++)
            if(u[j]&&(minn[j]<minn[k]))
                k=j;
        u[k]=0;
        for(int j=1;j<=n;j++)
            if(u[j] && g[k][j]!=0 && g[k][j]<minn[j])
                minn[j]=g[k][j];
    }
    for(int i=1;i<=n;++i){
        if(minn[i]>mmax)
            mmax=minn[i];
    }
    printf("%d %d",n-1,mmax);
}
