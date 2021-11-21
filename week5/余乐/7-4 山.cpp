#include <cstdio>
using namespace std;
int m,n,ans=0;
int map[3001][3001],u[3001][3001],dh[]={-1,0,0,1},dl[]={0,-1,1,0};
void y(int h,int l){
	u[h][l]=1;
	for(int i=0;i<4;i++){
		int H,L;
		H=dh[i]+h;
		L=dl[i]+l;
		if(map[H][L]&&!u[H][L]) y(H,L);
	} 
}
int main(){
	scanf("%d%d",&m,&n);
	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++)
			scanf("%d",&map[i][j]);
	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++)
			if(map[i][j]&&!u[i][j]){
				ans++;y(i,j);
			}
	printf("%d",ans);
	return 0;
} 
