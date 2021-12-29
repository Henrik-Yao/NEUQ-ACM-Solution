#include<bits/stdc++.h>
using namespace std;
#define N 2010
int dirx[4]={0,0,1,-1};
int diry[4]={1,-1,0,0};
int n,m,ux,uy,vx,vy,qian[N][N][2],cun[N][N],pan[N][N],dis[N][N];
queue<pair<int,int> >que;
void print(int x,int y){
	//cout<<qian[x][y][0]<<' '<<qian[x][y][1]<<endl;
	printf("(%d %d)",x-1,y-1);
	if(qian[x][y][0]==x&&qian[x][y][1]==y)
	return;
	else
	print(qian[x][y][0],qian[x][y][1]);
}
void bfs(int ux,int uy){
	que.push(make_pair(ux,uy));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			dis[i][j]=1e9;
		}
	}
	dis[ux][uy]=0;
	while(que.size()){
		int x=que.front().first,y=que.front().second;
		que.pop();
		if(pan[x][y])continue;
		pan[x][y]=1;
		if(x==vx&&y==vy){
			continue;
		}
		for(int i=0;i<4;i++){
			int dx=x+dirx[i],dy=y+diry[i];
			if(cun[dx][dy]==-1)continue;
			if(dis[dx][dy]>dis[x][y]+cun[x][y]){
				dis[dx][dy]=dis[x][y]+cun[x][y];
				que.push(make_pair(dx,dy));
				if(pan[dx][dy])pan[dx][dy]=0;
				qian[dx][dy][0]=x;
				qian[dx][dy][1]=y;
			}
		}
	}
}
int main(){
	cin>>m>>n;//
	cin>>ux>>uy>>vx>>vy;
	ux++;uy++;vx++;vy++;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>cun[i][j];
			if(cun[i][j]==-1)
			pan[i][j]=1;
			qian[i][j][0]=i;
			qian[i][j][1]=j;
		}
	}
	bfs(ux,uy);
	print(vx,vy);
	return 0;
}
