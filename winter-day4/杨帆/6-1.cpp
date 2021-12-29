#include<bits/stdc++.h>
using namespace std;
const int k = 105;
int G[k][k];
long long dis[k];

int main(){
    int n,m;
    while(cin >> n >> m){
        memset(dis,0,sizeof(dis));
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                G[i][j] = G[j][i] = 9999;
            }
        }
        for(int i=0; i<m; i++){
            int a,b,c;
            cin >> a >> b >> c;
            if(a == b)  G[a][b] = G[b][a] = 0;
            else{
                G[a][b] = c;
                G[b][a] = c;
            }
        }
        for(int k=0; k<n; k++){
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    if(G[i][j] > G[i][k]+G[k][j]){
                        G[i][j] = G[i][k] + G[k][j];
                    }
                }
            }
        }
        int ans = INT_MAX,pos = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i == j) continue;
                dis[i] += G[i][j];
            }
            if(ans > dis[i]){
                ans = dis[i];
                pos = i;
            }
        }
        cout << pos << endl;
    }
}
