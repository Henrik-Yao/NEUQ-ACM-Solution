#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int p = 1e3;
int G[p][p],path[p][p];

void print(int x,int y);
void Floyd(int n);

int main(){
    int n,m;
    cin >> n >> m;
    memset(path,-1,sizeof(path));
    memset(G,0x3f,sizeof(G));
    for(int i=0; i<n; i++){
        G[i][i] = 0;
    }
    for(int i=0; i<m; i++){
        int a,b,c;
        cin >> a >> b >> c;
        G[a][b] = c;
    }
    Floyd(n);
    for(int i=0; i<2; i++){
        int x,y;
        cin >> x >> y;
        cout << x << "->";
        if(G[x][y] > 1000000){
            cout << y << ":" << -1 << endl;
            continue;
        }
        print(x,y);
        cout << y << ":" << G[x][y] << endl;
    }
    int dx,dy,max_;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(G[i][j] > max_ && G[i][j] < inf){
                max_ = G[i][j],dx = i,dy = j;
            }
        }
    }
    cout << dx << "->";
    print(dx,dy);
    cout << dy << ":" << max_;
}

void Floyd(int n){
    for(int k=0; k<n; k++){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                int temp = G[i][k] + G[k][j];
                if(temp < G[i][j]){
                    G[i][j] = temp;
                    path[i][j] = k;
                }
            }
        }
    }
}

void print(int x,int y){
    if(path[x][y] == -1)    return;
    print(x,path[x][y]);
    cout << path[x][y] << "->";
    print(path[x][y],y);
}
