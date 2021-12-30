#include <iostream>
using namespace std;
const int N = 210, M = 2e+10, INF = 1e9;
int n, m, k, x, y, z;
int d[N][N];
void floyd() {
    for(int k = 0; k < n; k++){

        for(int i = 0; i < n; i++){
		
            for(int j = 0; j < n; j++){
			
			
                d[i][j] =d[j][i]= min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }

}
int main() {
    while(cin>>n>>m){
    for(int i = 0; i < n; i++)
        for(int j =0; j < n; j++)
            if(i == j) d[i][j] = 0;
            else d[i][j] = INF;
    while(m--) {
        cin >> x >> y >> z;
        d[x][y] = d[y][x]=min(d[x][y], z);
    }
    floyd();
    int sum[n+1]={};
    int index=-1;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            sum[i]+=d[i][j];
        }
    }//分别求到其他点的距离之和 
    int minn=INF;
    for(int i=0;i<n;i++){
        if(sum[i]<=minn){
        	if(minn==sum[i])index=min(index,i);//取小的下标 
        	else index=i;
            minn=sum[i];
        }
    }
        cout<<index<<endl;
}
    return 0;

}

