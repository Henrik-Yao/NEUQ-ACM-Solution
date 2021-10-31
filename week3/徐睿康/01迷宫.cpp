#include<bits/stdc++.h>
using namespace std;
int dirx[4]={0,0,1,-1};
int diry[4]={1,-1,0,0};
char c;
int n,m,x,y,cnt,pan[1010][1010],cun[1010][1010],f[1010][1010],xx,yy;
queue<pair<int,int> >que;
void bfs(int a,int b){
	cnt=1;
	que.push(make_pair(a,b));
	pan[a][b]=1;
	while(que.size()){
		x=que.front().first;
		y=que.front().second;
		que.pop();
		for(int i=0;i<4;i++){
			xx=x+dirx[i];
			yy=y+diry[i];
			if(xx>=1&&xx<=n&&yy>=1&&yy<=n&&pan[xx][yy]==0){
				if((f[x][y]==0&&f[xx][yy]==1)||(f[x][y]==1&&f[xx][yy]==0)){
					cnt++;
					pan[xx][yy]=1;
					que.push(make_pair(xx,yy));
				}
			}
		}
	}
}
void bfs1(int a,int b){
	que.push(make_pair(a,b));
	pan[a][b]=0;
	cun[a][b]=cnt;
	while(que.size()){
		x=que.front().first;
		y=que.front().second;
		que.pop();
		for(int i=0;i<4;i++){
			xx=x+dirx[i];
			yy=y+diry[i];
			if(xx>=1&&xx<=n&&yy>=1&&yy<=n&&pan[xx][yy]==1){
				pan[xx][yy]=0;
				cun[xx][yy]=cnt;
				que.push(make_pair(xx,yy));
			}
		}
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>c;
			f[i][j]=c-'0';
			cun[i][j]=-1;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(cun[i][j]==-1){
				bfs(i,j);
				bfs1(i,j);
			}
		}
	}
	/*for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cout<<cun[i][j]<<' ';
		}
	}*/
	while(m--){
		scanf("%d%d",&x,&y);
		printf("%d\n",cun[x][y]);
	}
	return 0;
}
