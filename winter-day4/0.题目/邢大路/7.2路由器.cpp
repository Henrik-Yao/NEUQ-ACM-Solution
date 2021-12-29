#include <iostream>
using namespace std;
const int N = 210, INF = 1e9;
int n, m, k, x, y, z;
int d[N][N];
void floyd() {
    for(int k = 0; k <n; k++){
        for(int i = 0; i <n; i++){
            for(int j = 0; j <n; j++){
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
}
int main() {
    while(cin>>n>>m){
    int count=n;
    for(int i = 0; i <n; i++){
        for(int j =0; j<n; j++){
            if(i == j) d[i][j] = 0;
            else d[i][j] = INF;
        }
    }
    while(count--) {
       int x,y;
	   int num;
	   cin>>x>>num;
	   for(int i=0;i<num;i++){
	    cin>>y;
        d[x][y] =min(d[x][y], 1);
     }
    }
    floyd();
    int a,b;
    while(m--){
    cin>>a>>b;
    if(d[a][b]>=1000000)cout<<"connection impossible"<<endl;
    else cout<<d[a][b]<<endl;
}
   
}
    
    return 0;

}
