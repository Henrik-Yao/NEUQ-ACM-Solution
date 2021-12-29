#include <bits/stdc++.h>
using namespace std;
#define N 120
#define inf 1000
void Dij(double a[N][N],int t,int h){
    double D[N];
    int P[N];
    bool visit[N];
    for(int i=0;i<N;i++)
        visit[i]=false;
    int v=t-1;
    for(int i=0;i<N;i++)
    {
        D[i]=a[v][i];
        if(D[i]!=inf){
            P[i]=v;
        }
        else P[i]=0;
    }
    visit[v]=true;
    D[v]=0;
    int temp;
    for(int i=0;i<N;i++){
        double min=200;
        for(int j=0;j<N;j++)
            if((!visit[j])&&D[j]<min){
                min=D[j];
                temp=j;
            }
        visit[temp]=true;
        for(int j=0;j<N;j++)
            if((!visit[j])&&D[j]>D[temp]+a[temp][j]){
                D[j]=D[temp]+a[temp][j];
                P[j]=temp+1;
            }
    }
    int i=h-1;
    int pre=P[i];
    int j=0,b[N];
    while(pre!=0){
        b[j]=pre;
        j++;
        pre=P[pre-1];
    }
    cout<<v<<"-->";
    for(int k=j-1;k>=0;k--){
        cout<<b[k]-1<<"-->";
    }
    if(D[i]!=inf) cout<<i<<":"<<D[i]<<endl;
}
int main(){
    int n,e;
    cin>>n>>e;
    double adj[N][N];
     for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            adj[i][j]=inf;
    for(int i=0;i<e/2;i++){
        int t,h;
        double w;
        cin>>t>>h>>w;
        adj[t][h]=w;
        adj[h][t]=w;
    }
    int start,end;
    cin>>start>>end;
    Dij(adj,start+1,end+1);
}
