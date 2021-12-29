#include<bits/stdc++.h>
using namespace std;
const int MAXN=210;
const int INF=0x3f3f3f;
int n,m;
int cons[MAXN][MAXN];
//输出的跳数最多为199，多于这个数说明不合法
int ans=-1;
void floyed(int a,int b){
    int i,j,k;
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(cons[i][j]>cons[i][k]+cons[k][j])
                cons[i][j]=cons[i][k]+cons[k][j];
            }
        }
    }
    ans=cons[a][b];
}
int main(){
    while(cin>>n>>m){
        memset(cons,INF,sizeof(cons));
        for(int u=0;u<n;u++){
        int i,k;
        cin>>i>>k;
        for(int j=0;j<k;j++){
            int to;
            cin>>to;
            if(i==to)cons[i][to]=0;
            else cons[i][to]=1;
        }
        }
        for(int u=0;u<m;u++){
            int a,b;
            cin>>a>>b;
            floyed(a,b);
            if(ans==-1||ans>=200)printf("connection impossible\n");
            else cout<<ans<<endl;
        }
    }
    return 0;
}