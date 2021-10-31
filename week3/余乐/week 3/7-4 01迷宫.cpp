#include <cstdio>
#include <iostream>
#define N 2001
using namespace std;
int n,m,tot=0,map[N][N],ans[N][N],pd[N][N];
void Y(int x,int y){
	tot++;pd[x][y]=1;
	if(map[x][y]!=map[x-1][y]&&x-1>0&&pd[x-1][y]==0) Y(x-1,y);
	if(map[x][y]!=map[x][y-1]&&y-1>0&&pd[x][y-1]==0) Y(x,y-1);
	if(map[x][y]!=map[x+1][y]&&x+1<=n&&pd[x+1][y]==0) Y(x+1,y);
	if(map[x][y]!=map[x][y+1]&&y+1<=n&&pd[x][y+1]==0) Y(x,y+1);
}
void l(int x,int y){
	ans[x][y]=tot;
	if(map[x][y]!=map[x-1][y]&&x-1>0&&ans[x-1][y]==0) l(x-1,y);
	if(map[x][y]!=map[x][y-1]&&y-1>0&&ans[x][y-1]==0) l(x,y-1);
	if(map[x][y]!=map[x+1][y]&&x+1<=n&&ans[x+1][y]==0) l(x+1,y);
	if(map[x][y]!=map[x][y+1]&&y+1<=n&&ans[x][y+1]==0) l(x,y+1);
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++){
			char a;cin>>a;
			map[i][j]=a-'0';
		}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(ans[i][j]==0){
				tot=0;
				Y(i,j);l(i,j);
			}
	for(int i=1;i<=m;i++){
		int a,b;scanf("%d%d",&a,&b);
		printf("%d",ans[a][b]);
		if(i<m) printf("\n");
	}
	return 0;
}
