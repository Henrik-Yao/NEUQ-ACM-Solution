#include<bits/stdc++.h>
using namespace std;
int dirx[8]={1,1,1,0,0,-1,-1,-1};
int diry[8]={1,0,-1,1,-1,1,0,-1};
queue<pair<int,int> >que;
int pan[30][30],cun[30][30],mine[30][30],n,m,k,l,x,y,cnt=0,xx,yy;
void bfs(int a,int b){
	cnt++;
	pan[a][b]=1;
	if(cun[a][b]==0)
	que.push(make_pair(a,b));
	while(que.size()){
		x=que.front().first;
		y=que.front().second;
		que.pop();
		for(int i=0;i<8;i++){
			xx=x+dirx[i];
			yy=y+diry[i];
			if(xx>=1&&xx<=n&&yy>=1&&yy<=m&&pan[xx][yy]==0&&mine[xx][yy]!=1){
				pan[xx][yy]=1;
				cnt++;
				if(cun[xx][yy]!=0)continue;
				else{
					que.push(make_pair(xx,yy));
				}
			}
		}
	}
}
int main(){
	cin>>n>>m>>k>>l;
	for(int i=1;i<=k;i++){
		scanf("%d%d",&x,&y);
		x++;y++;
		mine[x][y]=1;
		cun[x+1][y]++;
		cun[x+1][y+1]++;
		cun[x+1][y-1]++;
		cun[x][y+1]++;
		cun[x][y-1]++;
		cun[x-1][y]++;
		cun[x-1][y+1]++;
		cun[x-1][y-1]++;
	}
	while(l--){
		scanf("%d%d",&x,&y);
		x++;y++;
		if(mine[x][y]==1){
			cout<<"You lose";
			return 0;
		}
		if(pan[x][y]==1)continue;
		bfs(x,y);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(pan[i][j]==0)printf("-1 ");
				else printf("%d ",cun[i][j]);
			}
			printf("\n");
		}
		if(cnt==((n*m)-k)){
			cout<<"You win";
			return 0;
		}
		printf("\n");
	}
	return 0;
}
