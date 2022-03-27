#include<bits/stdc++.h>
using namespace std;
const int MAXN=105;
const int INF=0x3f3f3f3f;
int d[MAXN][MAXN];
int path[MAXN][MAXN];
int n,m;
void floyed(){
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            if(d[i][k]==INF)continue;
            for(int j=0;j<n;j++){
                if(d[i][j]>d[i][k]+d[k][j]){
                    d[i][j]=d[i][k]+d[k][j];
                    path[i][j]=k;//表面i与j间使用了结点k；方便后续打印；
                }
            }
        }
    }
}
void put(int a,int b){
    if(path[a][b]==INF)return;
    put(a,path[a][b]);
    cout<<path[a][b]<<"->";
    put(path[a][b],b);
}
int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j) d[i][j]=0;
            else d[i][j]=INF;
            path[i][j]=INF;
        }
    }
    int a,b,c;
    for(int i=0;i<m;i++){
        cin>>a>>b>>c;
        d[a][b]=c;
    }
    floyed();
    int x,y;
    for(int i=0;i<2;i++){
        cin>>x>>y;
        cout<<x<<"->";
        put(x,y);
        cout<<y<<":";
        if(d[x][y]!=INF)cout<<d[x][y]<<endl;
        else{
            cout<<"-1"<<endl;
        }
    }
    int sta=0,end=0,maxx=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(d[i][j]>maxx&&d[i][j]<INF){
                maxx=d[i][j];
                sta=i;
                end=j;
            }
        }
    }
    cout<<sta<<"->";
    put(sta,end);
    cout<<end<<":"<<d[sta][end];

    return 0;
}