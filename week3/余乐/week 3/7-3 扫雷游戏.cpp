#include <cstdio>
using namespace std;
int n,m,k,l,dl[21][21],map[21][21],v[21][21],x[]={-1,-1,-1,0,0,1,1,1},y[]={-1,0,1,-1,1,-1,0,1};
void yl(int a,int b){
	if(dl[a][b]||map[a][b]!=-1) return;
	v[a][b]=1;
	int tot=0;
	for(int i=0;i<=7;i++){
		int X=a+x[i],Y=b+y[i];
		if(X<0||X>=n||Y<0||Y>=m) continue;
		if(dl[X][Y]) tot++;
	}
	map[a][b]=tot;
	if(tot==0) 
		for(int i=0;i<=7;i++){
			int X=a+x[i],Y=b+y[i];
			if(X<0||X>=n||Y<0||Y>=m||v[X][Y]) continue;
			yl(X,Y);
		}
}
int main(){
	scanf("%d%d%d%d",&n,&m,&k,&l);
	for(int i=1;i<=k;i++){
		int a,b;scanf("%d%d",&a,&b);
		dl[a][b]=1;
	}
	for(int i=0;i<n;i++)
		for(int p=0;p<m;p++)
			map[i][p]=-1;
	for(int i=1;i<=l;i++){
		int a,b;scanf("%d%d",&a,&b);
		if(dl[a][b]) {
			printf("You lose\n");
			break;
		}
		if(map[a][b]!=-1) continue;
		for(int j=0;j<n;j++)
			for(int p=0;p<m;p++)
				v[j][p]=0;
		yl(a,b);
		for(int j=0;j<n;j++){
			for(int p=0;p<m;p++)
				printf("%d ",map[j][p]);
			printf("\n");
		}
		int pd=k;
		for(int j=0;j<n;j++)
			for(int p=0;p<m;p++)
				if(map[j][p]==-1) pd--;
		if(pd==0) printf("You win");
		printf("\n");
	}
	return 0;
}
