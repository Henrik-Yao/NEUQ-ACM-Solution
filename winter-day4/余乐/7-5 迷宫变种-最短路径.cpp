#include <queue>
#include <cstdio>
#define inf 65535
#define N 1001
using namespace std;

int m,n,sx,sy,ex,ey,map[N][N],u[N][N],dis[N][N];
int dx[]={-1,0,0,1},dy[]={0,-1,1,0};

struct s{
	int x,y;
}fa[N][N];
struct ss{
	int x,y,c;
	bool operator < (const ss &r)const{return r.c < c;}
};

int main(){
	scanf("%d%d%d%d%d%d",&m,&n,&sx,&sy,&ex,&ey);
	sx ++;sy ++;ex ++;ey ++;
	for(int i = 1;i <= n;i ++)
		for(int j = 1;j <= m;j ++){
			scanf("%d",&map[i][j]);
			dis[i][j] = inf;
		}
	dis[sx][sy] = 0;
	priority_queue<ss> q;
	q.push((ss){sx , sy , 0});
	while(!q.empty()){
		ss now = q.top();
		q.pop();
		int x = now.x,y = now.y;
		if(u[x][y]) continue;
		u[x][y] = 1;
		for(int i = 0;i < 4;i ++){
			int tx = x + dx[i],ty = y + dy[i];
			if(map[tx][ty] == -1) continue;
			if(!u[tx][ty] && dis[tx][ty] > dis[x][y] + map[tx][ty]){
				dis[tx][ty] = dis[x][y] + map[tx][ty];
				fa[tx][ty] = (s){x , y};
				q.push((ss){tx , ty , dis[tx][ty]});
			}
		}
	}
	printf("(%d %d)",ex - 1,ey - 1);
	int X = ex,Y = ey;
	while(1){
		s now = fa[X][Y];
		X = now.x;Y = now.y;
		printf("(%d %d)",X - 1,Y - 1);
		if(X == sx && Y == sy) break;
	}
	return 0;
}
