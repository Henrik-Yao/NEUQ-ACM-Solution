#include<bits/stdc++.h>
using namespace std;
const int k = 1e3;
int G[k][k];

int main(){
    int n,m;
    while(cin >> n >>  m){
        int a;
        memset(G,0,sizeof(G));
        for(int i=0; i<n; i++){
            G[i][i] = 0;
            for(int j=i+1; j<n; j++){
                G[i][j] = G[j][i] = 1e9;
            }
        }
        for(int i=0; i<n; i++){
            int id,k;
            cin >> id >> k;
            for(int j=0; j<k; j++){
                int x;
                cin >> x;
                G[id][x] = 1;
            }
        }
        for(int k=0; k<n; k++){
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    G[i][j] = min(G[i][j],G[i][k]+G[k][j]);
                }
            }
        }
        for(int i=0; i<m; i++){
            int a,b;
            cin >> a >> b;
            if(G[a][b] < 1e9){
                cout << G[a][b] << endl;
            }
            else{
                cout << "connection impossible\n";
            }
        }
    }
}
