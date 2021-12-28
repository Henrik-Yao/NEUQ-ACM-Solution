#include<bits/stdc++.h>
using namespace std;
const int INF=0x3f3f3f3f;
const int MAXN=310;
bool vst[MAXN]={0};
int cost[MAXN][MAXN];//邻接矩阵
int lowc[MAXN];//储存已经加入的点中，距离别的点最小距离
int N,M;
int s=0,ans=0;
void prim(int n){
   vst[1]=true;
    for(int i=2;i<=n;i++)lowc[i]=cost[1][i];
    for(int i=1;i<n;i++){
        int minc=INF;
        int p=-1;
        for(int j=1;j<=n;j++){
            if(!vst[j]&&minc>lowc[j]){
            minc=lowc[j];
            p=j;
        }
        }

        if(ans<minc) ans=minc;

        vst[p]=true;
        
        s++;
        for(int j=1;j<=n;j++){
            if(!vst[j]&&lowc[j]>cost[p][j])
            lowc[j]=cost[p][j];
        }
    }
}
int main(){
    scanf("%d %d",&N,&M);
    for(int i=1;i<=N;i++){
    	for(int j=1;j<=N;j++)
    	cost[i][j]=INF;
	}
    for(int i=1;i<=M;i++){
        int i1,i2,powe;
        scanf("%d %d %d",&i1,&i2,&powe);
        cost[i1][i2]=powe;
        cost[i2][i1]=powe;
    }
    prim(N);
    printf("%d %d",s,ans);
    return 0;
}