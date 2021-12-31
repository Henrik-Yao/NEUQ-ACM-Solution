#include <iostream>
#include <queue>
using namespace std;
int dx[4]={1,0,-1,0};
int dy[4]={0,-1,0,1};
int m[1005][1005];
int memo[1005][1005];
int blockarea[1000005];
struct point{
	int x;
	int y;
};
queue<point> road;
int main(){
	int n,mm;
	cin >> n >> mm;
	char chnu;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin >> chnu;
			m[i][j]=chnu-'0';
		}
	}
	int block=0;
	int nexty,nextx,startx,starty;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(memo[i][j]==0){
				block++;
				int sum=1;
				int flag=0;
			//	cin >> startx >> starty;
				point start,next;
				start.x=i;
				start.y=j;
				road.push(start);
				memo[i][j]=block;
				while(!road.empty()){
					start=road.front();
					for(int k=0;k<4;k++){
						next.x=start.x+dx[k];
						next.y=start.y+dy[k];
						if(next.x<=n&&next.y<=n&&next.x>0&&next.y>0&&m[next.x][next.y]!=m[start.x][start.y]&&memo[next.x][next.y]==0){
						//	printf("Here I got %d %d\n",next.x,next.y);
							road.push(next);
							memo[next.x][next.y]=block;
							sum++;
						}
					}
					road.pop();
				}
			//	cout << ans << endl;
				blockarea[block]=sum;
			}
		}
	}
	for(int abs=1;abs<=mm;abs++){
		cin >> startx >> starty;
		cout << blockarea[memo[startx][starty]] << endl;
	}
	return 0;
}