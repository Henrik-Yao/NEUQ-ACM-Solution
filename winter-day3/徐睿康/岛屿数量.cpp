#include<bits/stdc++.h>
using namespace std;
int dirx[4]={0,0,1,-1};
int diry[4]={1,-1,0,0};
int n,m,a[110][110],pan[110][110],cnt=0;
queue<pair<int,int> >que;
void bfs(int ux,int uy){
	que.push(make_pair(ux,uy));
	while(que.size()){
		int x=que.front().first,y=que.front().second;
		//cout<<x<<' '<<y<<endl;
		que.pop();
		for(int i=0;i<4;i++){
			int dx=x+dirx[i],dy=y+diry[i];
			if(dx>=1&&dx<=n&&dy>=1&&dy<=m&&a[dx][dy]==1&&pan[dx][dy]==0){
				pan[dx][dy]=1;
				que.push(make_pair(dx,dy));
			}
		}
	}
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)cin>>a[i][j];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]==1&&pan[i][j]==0){
				cnt++;
				pan[i][j]=1;
				bfs(i,j);
			}
		}
	}
	cout<<cnt;
	return 0;
}
