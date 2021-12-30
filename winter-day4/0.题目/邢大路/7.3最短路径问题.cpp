#include <bits/stdc++.h>
using namespace std;
const int N = 210, INF = 1e9;
int n, m,x,y,z;
int d[N][N];
int pass[205][205];
int sum;
void floyd()
{
	for(int k=0;k<n;k++)
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				if(d[i][j]>d[i][k]+d[k][j]){
					d[i][j]=d[i][k]+d[k][j];
					pass[i][j]=k;
				}
}

void print(int i,int j){
	if(i==j)return;
	if(pass[i][j]==-1)cout<<i<<"-->",sum+=d[i][j];
	else{
		print(i,pass[i][j]);
		print(pass[i][j],j);
	}
}
int main() {
	memset(pass,-1,sizeof(pass));
    cin>>n>>m;
    for(int i = 0; i <n; i++){
        for(int j =0; j<n; j++){
            if(i == j) d[i][j] = 0;
            else d[i][j] = INF;
        }
    }
            m=m/2;
    while(m--) {
        cin >> x >> y >> z;
        d[x][y] = d[y][x]=z;
    }
    floyd();
    int a,b;
    cin>>a>>b;
    if(a==b){printf("%d-->%d:0",a,a);return 0;}
    print(a,b);
   cout<<b<<":"<<sum;
    return 0;

}

