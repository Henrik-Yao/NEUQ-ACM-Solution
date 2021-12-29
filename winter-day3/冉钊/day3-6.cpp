#include<bits/stdc++.h>
using namespace std;
const int INF=0x3f3f3f3f;
const int MAXN=1510;
int N,E;
bool vst[MAXN];
int cost[MAXN][MAXN];
int lowc[MAXN];
int s=0,ans=0,flag=1;
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
        if(p==-1){
            flag=0;
            printf("There is no minimum spanning tree.\n");
            return;
        }
        ans+=minc;
        vst[p]=true;
        
        s++;
        for(int j=1;j<=n;j++){
            if(!vst[j]&&lowc[j]>cost[p][j])
            lowc[j]=cost[p][j];
        }
    }
}
int main(){
    while(cin>>N>>E){
        for(int i=1;i<=N;i++){
    	for(int j=1;j<=N;j++)
    	cost[i][j]=INF;
	}
    for(int i=1;i<=E;i++){
        int i1,i2,powe;
        scanf("%d %d %d",&i1,&i2,&powe);
        cost[i1][i2]=powe;
        cost[i2][i1]=powe;
    }
    prim(N);
    if(flag)printf("%d\n",ans);
    }
    return 0;
}
