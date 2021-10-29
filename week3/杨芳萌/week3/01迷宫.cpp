#include<bits/stdc++.h>
using namespace std;
char map_[1001][1001];
int ans[1000001];
int flag[1001][1001];
int dx[4]= {1,0,-1,0};
int	dy[4]= {0,1,0,-1};
struct node {
	int x,y;
}q[1000001];
		
int main() {
	int n,m,nx,ny,sx,sy,d,f,r,sum;
	cin>>n>>m;
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++)
			cin>>map_[i][j];
	d=0;	
	for(int i=1; i<=n; i++)
		for(int j=1;j<=n;j++)
			if(flag[i][j]==0){
				d++;
				f=1; r=1;
				q[f].x=i; q[f].y=j;
				flag[i][j]=d;
				sum=1;
				while(f<=r){
					for(int k=0;k<4;k++){
						nx=q[f].x+dx[k];
						ny=q[f].y+dy[k];
						if(flag[nx][ny]==0&&nx>=1&&nx<=n&&ny>=1&&ny<=n&&((map_[nx][ny]=='1'&&map_[q[f].x][q[f].y]=='0')||(map_[nx][ny]=='0'&&map_[q[f].x][q[f].y]=='1'))){
						   	r++;
						   	sum++;
						   	flag[nx][ny]=d;
						   	q[r].x=nx;
						   	q[r].y=ny;
						}	   
					}
					f++;
				}
				ans[d]=sum;
			}
	for(int i=1;i<=m;i++){
		cin>>sx>>sy;
		cout<<ans[flag[sx][sy]]<<endl;
	}
	return 0;
}
