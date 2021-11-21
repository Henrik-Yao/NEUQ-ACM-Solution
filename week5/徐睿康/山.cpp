#include<bits/stdc++.h>
using namespace std;
int dirx[4]={1,-1,0,0};
int diry[4]={0,0,1,-1};
int n,m,cnt=0,x,y,xx,yy,a[2010][2010];
queue<pair<int,int> >que;
void bfs(int ux,int uy){
	que.push(make_pair(ux,uy));
	while(que.size()){
		x=que.front().first;
		y=que.front().second;
		que.pop();
		if(a[x][y]==0)continue;
		a[x][y]=0;
		for(int i=0;i<4;i++){
			xx=x+dirx[i];
			yy=y+diry[i];
			if(xx>=1&&xx<=n&&yy>=1&&yy<=m&&a[xx][yy]==1){
				que.push(make_pair(xx,yy));
			}
		}
	}
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]==1){
				cnt++;
				bfs(i,j);
			}
		}
	}
	printf("%d",cnt);
	return 0;
}
