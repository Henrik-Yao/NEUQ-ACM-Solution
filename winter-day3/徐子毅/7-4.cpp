#include <iostream>
#include <queue>
using namespace std;
int _map[105][105];
int vis[105][105];
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
struct point{
	int x;
	int y;
};
int island=0;
queue<point> que;
int main(){
	int M,N;
	cin >> M >> N;
	for(int i=1;i<=M;i++) for(int j=1;j<=N;j++) cin >> _map[i][j];
	for(int i=1;i<=M;i++){
		for(int j=1;j<=N;j++){
			if(vis[i][j]==0&&_map[i][j]==1){
				point start;
				start.x=i;
				start.y=j;
				que.push(start);
				vis[start.x][start.y]=1;
				while(!que.empty()){
					start=que.front();
					point next;
					for(int k=0;k<4;k++){
						next.x=start.x+dx[k];
						next.y=start.y+dy[k];
						if(_map[next.x][next.y]==1&&vis[next.x][next.y]==0){
							que.push(next);
							vis[next.x][next.y]=1;
						}
					}
					que.pop();
				}
				island++;
			}
		}
	}
	cout << island << endl;
	return 0;
}